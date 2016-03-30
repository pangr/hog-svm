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
	hog.detectMultiScale(src, found, 0, Size(4, 4), Size(), 1.02, 1);//对图片进行多尺度行人检测
	qDebug() << "number:" << found.size() << endl;

	//找出所有没有嵌套的矩形框r,并放入found_filtered中,如果有嵌套的话,则取外面最大的那个矩形框放入found_filtered中
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

	//画矩形框，因为hog检测出的矩形框比实际人体框要稍微大些,所以这里需要做一些调整
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
	waitKey();//注意：imshow之后必须加waitKey，否则无法显示图像


	/******************读入单个64*128的测试图并对其HOG描述子进行分类*********************/
	//读取测试图片(64*128大小)，并计算其HOG描述子
	//   Mat testImg = imread("6f.jpg");

	//vector<float> descriptor;
	//hog.compute(testImg, descriptor, Size(8, 8));//计算HOG描述子，检测窗口移动步长(8,8)
	//Mat testFeatureMat = Mat::zeros(1, 4752, CV_32FC1);//测试样本的特征向量矩阵
	////将计算好的HOG描述子复制到testFeatureMat矩阵中
	//for (int i = 0; i<descriptor.size(); i++)
	//	testFeatureMat.at<float>(0, i) = descriptor[i];

	////用训练好的SVM分类器对测试图片的特征向量进行分类
	//int result = svm.predict(testFeatureMat);//返回类标
	//cout << "分类结果：" << result <<endl;

}
void detectAvi(char* avipath, HOGDescriptor hog)
{
	hog.load("HOG_Detector.xml");
	/**************读入图片进行HOG行人检测******************/
	cvNamedWindow("img", 1);
	CvCapture * cap = cvCaptureFromAVI(avipath);
	IplImage  *src;
	vector<Rect> found, found_filtered;//矩形框数组
	if (cap)
	{
		while (src = cvQueryFrame(cap))
		{
			hog.detectMultiScale(src, found, 0, Size(8, 8), Size(0, 0), 1.05, 2);//对图片进行多尺度行人检测
			if (found.size() > 0)
			{
				for (int i = 0; i<found.size(); i++)
				{
					CvRect tempRect = cvRect(found[i].x, found[i].y, found[i].width, found[i].height);

					cvRectangle(src, cvPoint(tempRect.x, tempRect.y),
						cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(220, 0, 0), 2);
				}
			}
			cvShowImage("img", src);//显示当前帧  
			char c = cvWaitKey(1);
			if (c == 27)
			{
				break;
			}
		}
	}
}
