#ifndef QTTEST_H
#define QTTEST_H

#include <QtWidgets/QMainWindow>
#include <Qlabel>
#include <QTimer>
#include <QtGui\QPaintEvent>  
#include "ui_mainWin.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>

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
	IplImage *tmp;
	IplImage *dettmp;
protected:
	void paintEvent(QPaintEvent *e);
	QImage *cvIpImgtoQimg();
    void dopicture();
private slots:
    void OpenImageClicked();
	void pictureCapture();
	void nextframe();
	void selectpic();
	void train();
	void updateplain();
};

#endif // QTTEST_H
