#include "trainer.h"
#include <qdebug.h>

string strtmp;

double * hogSVM::get_alpha_vector()
{
	return this->decision_func->alpha;
}
float hogSVM::get_rho()
{
	return this->decision_func->rho;
}

void samplesTrain(string imgpa, Mat &sampleFeatureMat, Mat &sampleLabelMat, int firstnum, HOGDescriptor &hog, float label,QPlainTextEdit *& plain)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string imgpath;
	cout << imgpa << endl;
	long hfile2 = 0;

	if ((hFile = _findfirst(imgpath.assign(imgpa).append("\\*").c_str(), &fileinfo)) != -1)
	{
		int num = firstnum;
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{

			}
			else
			{
				qDebug("doing %s-------%d\n", fileinfo.name,num);
				imgpath.assign(imgpa).append("\\").append(fileinfo.name);
				Mat src = imread(imgpath);
				vector<float> descriptors;
				hog.compute(src, descriptors, Size(8, 8));
				for (int i = 0; i<descriptors.size(); i++)
					sampleFeatureMat.at<float>(num, i) = descriptors[i];
				sampleLabelMat.at<float>(num, 0) = label;
				num++;
			}
		} while (_findnext(hFile, &fileinfo) == 0);
	}
}

void svmTrain(HOGDescriptor hog, string posdir, string negdir, char* savepath, QPlainTextEdit *& plain)
{
	int DescriptorDim = hog.getDescriptorSize();
	int posSamNO = fileCounts(posdir);
	int negSamNO = fileCounts(negdir);
	char * a;
	qDebug("%d,%d",posSamNO,negSamNO);
	Mat sampleFeatureMat = Mat::zeros(posSamNO + negSamNO, DescriptorDim, CV_32FC1);
	Mat sampleLabelMat = Mat::zeros(posSamNO + negSamNO, 1, CV_32FC1);
	hogSVM svm;

	samplesTrain(posdir, sampleFeatureMat, sampleLabelMat, 0, hog, 1,plain);
	samplesTrain(negdir, sampleFeatureMat, sampleLabelMat, posSamNO, hog, -1,plain);

	qDebug() << "SVM training" << endl;
	CvTermCriteria criteria = cvTermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 2147483647, FLT_EPSILON);
	CvSVMParams param(CvSVM::C_SVC, CvSVM::LINEAR, 0, 1, 0, 0.01, 0, 0, 0, criteria);
	svm.train(sampleFeatureMat, sampleLabelMat, Mat(), Mat(),param);//ÑµÁ··ÖÀàÆ÷
	qDebug() << "train over" << endl;
	svm.save(savepath);
}

void hogTrain(char* svmpath, char* hogpath, HOGDescriptor hog,  QPlainTextEdit *& plain)
{
	hogSVM svm;
	svm.load(svmpath);
	int DescriptorDim = svm.get_var_count();
	int supportVectorNum = svm.get_support_vector_count();
	qDebug() << "hold number:" << supportVectorNum << endl;
	Mat alphaMat = Mat::zeros(1, supportVectorNum, CV_32FC1);
	Mat supportVectorMat = Mat::zeros(supportVectorNum, DescriptorDim, CV_32FC1);
	Mat resultMat = Mat::zeros(1, DescriptorDim, CV_32FC1);

	for (int i = 0; i<supportVectorNum; i++)
	{
		const float * pSVData = svm.get_support_vector(i);
		for (int j = 0; j<DescriptorDim; j++)
		{
			supportVectorMat.at<float>(i, j) = pSVData[j];
		}
	}

	double * pAlphaData = svm.get_alpha_vector();
	for (int i = 0; i<supportVectorNum; i++)
	{
		alphaMat.at<float>(0, i) = pAlphaData[i];
	}
	resultMat = -1 * alphaMat * supportVectorMat;
	vector<float> svmDetector;
	for (int i = 0; i<DescriptorDim; i++)
	{
		svmDetector.push_back(resultMat.at<float>(0, i));
	}
	svmDetector.push_back(svm.get_rho());
	qDebug() << "detecternum:" << svmDetector.size() << endl;
	hog.setSVMDetector(svmDetector);
	hog.save(hogpath);
}

int fileCounts(string savedir)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string imgpath;
	int num = 0;
	if ((hFile = _findfirst(imgpath.assign(savedir).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{

			}
			else
			{
				num++;
			}
		} while (_findnext(hFile, &fileinfo) == 0);
	}
	return num;
}
