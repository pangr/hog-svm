#pragma once
#pragma execution_character_set("utf-8")

#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>
#include <qplaintextedit.h>

using namespace std;
using namespace cv;

void samplesTrain(string imgpa, Mat &sampleFeatureMat, Mat &sampleLabelMat, int firstnum, HOGDescriptor &hog, float label, QPlainTextEdit *& plain);
void svmTrain(HOGDescriptor hog, string posdir, string negdir, char* savepath, QPlainTextEdit *& plain);
void hogTrain(char* svmpath, char* hogpath, HOGDescriptor hog, QPlainTextEdit *& plain);

int fileCounts(string savedir);

class hogSVM : public CvSVM
{
public:
	//���SVM�ľ��ߺ����е�alpha����
	double * get_alpha_vector();
	//���SVM�ľ��ߺ����е�rho����,��ƫ����
	float get_rho();
};

#endif 