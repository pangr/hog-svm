#include "detect.h"
#include <qdebug.h>

int detectframe(IplImage * &frame,IplImage * &img,IplImage * &imgtmp,int num, vector<Rect> &found,HOGDescriptor &hog,char * savepath,CvRect &rect)
{
	char tmpfile[10] = { '\0' };
	
	return num;
}
void detectImage(string imgpath, char * hogpath, HOGDescriptor hog, QPlainTextEdit *& plain)
{

	Mat src = imread(imgpath);
	vector<Rect> found, found_filtered;
	hog.load(hogpath);
	qDebug() << "detecting" << endl;
	hog.detectMultiScale(src, found, 0, Size(4, 4), Size(), 1.02, 1);//��ͼƬ���ж�߶����˼��
	qDebug() << "number:" << found.size() << endl;

	//�ҳ�����û��Ƕ�׵ľ��ο�r,������found_filtered��,�����Ƕ�׵Ļ�,��ȡ���������Ǹ����ο����found_filtered��
	for (int i = 0; i < found.size(); i++)
	{
		Rect r = found[i];
		int j = 0;
		for (; j < found.size(); j++)
			if (j != i && (r & found[j]) == r)
				break;
		if (j == found.size())
			found_filtered.push_back(r);
	}

	//�����ο���Ϊhog�����ľ��ο��ʵ�������Ҫ��΢��Щ,����������Ҫ��һЩ����
	for (int i = 0; i<found_filtered.size(); i++)
	{
		Rect r = found_filtered[i];
		r.x += cvRound(r.width*0.1);
		r.width = cvRound(r.width*0.8);
		r.y += cvRound(r.height*0.07);
		r.height = cvRound(r.height*0.8);
		rectangle(src, r.tl(), r.br(), Scalar(0, 0, 255), 2);
	}

	imwrite("ImgProcessed.jpg", src);
	namedWindow("src", 0);
	imshow("src", src);
	waitKey();//ע�⣺imshow֮������waitKey�������޷���ʾͼ��


	/******************���뵥��64*128�Ĳ���ͼ������HOG�����ӽ��з���*********************/
	//��ȡ����ͼƬ(64*128��С)����������HOG������
	//   Mat testImg = imread("6f.jpg");

	//vector<float> descriptor;
	//hog.compute(testImg, descriptor, Size(8, 8));//����HOG�����ӣ���ⴰ���ƶ�����(8,8)
	//Mat testFeatureMat = Mat::zeros(1, 4752, CV_32FC1);//����������������������
	////������õ�HOG�����Ӹ��Ƶ�testFeatureMat������
	//for (int i = 0; i<descriptor.size(); i++)
	//	testFeatureMat.at<float>(0, i) = descriptor[i];

	////��ѵ���õ�SVM�������Բ���ͼƬ�������������з���
	//int result = svm.predict(testFeatureMat);//�������
	//cout << "��������" << result <<endl;

}
void detectAvi(char* avipath, HOGDescriptor hog)
{
	hog.load("HOG_Detector.xml");
	/**************����ͼƬ����HOG���˼��******************/
	cvNamedWindow("img", 1);
	CvCapture * cap = cvCaptureFromAVI(avipath);
	IplImage  *src;
	vector<Rect> found, found_filtered;//���ο�����
	if (cap)
	{
		while (src = cvQueryFrame(cap))
		{
			hog.detectMultiScale(src, found, 0, Size(8, 8), Size(0, 0), 1.05, 2);//��ͼƬ���ж�߶����˼��
			if (found.size() > 0)
			{
				for (int i = 0; i<found.size(); i++)
				{
					CvRect tempRect = cvRect(found[i].x, found[i].y, found[i].width, found[i].height);

					cvRectangle(src, cvPoint(tempRect.x, tempRect.y),
						cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(220, 0, 0), 2);
				}
			}
			cvShowImage("img", src);//��ʾ��ǰ֡  
			char c = cvWaitKey(1);
			if (c == 27)
			{
				break;
			}
		}
	}
}
