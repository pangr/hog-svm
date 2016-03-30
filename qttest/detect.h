#ifndef DETECT_H
#define DETECT_H

#include <iostream>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/ml/ml.hpp>
#include <qplaintextedit.h>

using namespace std;
using namespace cv;

void detectImage(string imgpath, char * hogpath, HOGDescriptor hog, QPlainTextEdit *& plain);
void detectAvi(char* avipath, HOGDescriptor hog);
int detectframe(IplImage * &frame, IplImage * &img, IplImage * &imgtmp, int num, vector<Rect> &found, HOGDescriptor &hog, char * savepath,CvRect &rect);

#endif