#pragma once
#pragma execution_character_set("utf-8")

#ifndef QTTEST_H
#define QTTEST_H

#include <QtWidgets/QMainWindow>
#include <Qlabel>
#include <QTimer>
#include <string>
#include <QtGui\QPaintEvent>  
#include "ui_mainWin.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <follower.h>
#include <ctime>
#include <dialog.h>

using namespace std;
using namespace cv;

class qttest : public QMainWindow
{
	Q_OBJECT

public:
	qttest(QWidget *parent = 0);
	~qttest();

private:
	Ui::qttestClass ui;
	cv::Mat image;
	cv::Mat result;
	QTimer *timer;
	CvCapture *capture;
	IplImage *frame;
	IplImage *ipimage;
	QImage *qImg;
	vector<Rect> fod;
	CvRect inRect;
	CvRect outRect;
	HOGDescriptor hog;
	kalman  *kal;
	float start, finish;
	bool ispause;
protected:
	void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);
public:
	QImage *cvIpImgtoQimg();
    void dopicture(HOGDescriptor &hog);
private slots:
    void OpenImageClicked();
	void pictureCapture();
	void nextframe();
	void selectpic();
	void train();
	void updateplain();
	void receiveData(hogSize);
};

#endif // QTTEST_H
