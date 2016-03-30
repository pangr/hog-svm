#include "mainWin.h"

#include <QTime>
#include <qfileinfo.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <QtGui\qpainter.h>
#include <QtCore\QPoint>
#include <aviplayer.h>
#include <qdebug.h>
#include <trainer.h>
#include <picSelect.h>

qttest::qttest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.plainTextEdit->setReadOnly(true);
	timer = new QTimer(this);
	capture = NULL;
	qImg = NULL;
	connect(ui.selectpic,SIGNAL(clicked()),this,SLOT(selectpic()));
	connect(ui.train, SIGNAL(clicked()), this, SLOT(train()));

}

qttest::~qttest()
{
	//cvReleaseImage(&ipimage);
	if (capture != NULL)
	{
		cvReleaseCapture(&capture);
	}
	delete qImg;   
	delete timer;
}
void qttest::OpenImageClicked()
{
	QString file_full;
	QFileInfo fi;
	char *fp;
	file_full = QFileDialog::getOpenFileName(this);
	fi = QFileInfo(file_full);
	std::string str = file_full.toStdString();
	const char *fpp = str.c_str();

	if (*fpp != NULL)
	{
		capture = cvCaptureFromAVI(fpp);
		if (capture)
		{
			frame = cvQueryFrame(capture);
			
			if (frame)
			{
				dopicture();
				timer->setInterval(30);
				connect(timer, SIGNAL(timeout()), this, SLOT(nextframe()));
				timer->start();

			}
		}
	}
	
}
void qttest::pictureCapture()
{
	aviplayer *aper = new aviplayer;
	aper->playavi("F:\\test1.avi","F:\\tmp");
	//aper->dopicture("F:\\tmpfalse","F:\\falsetmp");
}

void qttest::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	if (qImg != NULL)
	{
		painter.drawImage(QPoint(200, 20), *qImg);
	}
}
	

void qttest::nextframe()
{
	frame = cvQueryFrame(capture);
	dopicture();
	this->update();
}

void qttest::dopicture()
{
	HOGDescriptor hog(Size(192, 32), Size(16, 16), Size(8, 8), Size(8, 8), 18);
	hog.load("HOG_Detector.xml");
	cvSetImageROI(frame, cvRect(frame->width*0.5, 0, frame->width*0.5, frame->height));
	tmp = cvCreateImage(cvSize(frame->width*0.5, frame->height), frame->depth, frame->nChannels);
	cvCopy(frame, tmp);
	this->resize(tmp->width + 220, tmp->height + 100);
	cvCvtColor(tmp, tmp, CV_BGR2RGB);
	cvSetImageROI(tmp, cvRect(0, 0, tmp->width, tmp->height * 0.25));
	dettmp = cvCreateImage(cvSize(tmp->width, tmp->height * 0.25), tmp->depth, tmp->nChannels);
	cvCopy(tmp,dettmp);
	vector<Rect> found;
	hog.detectMultiScale(dettmp, found, 0, Size(8, 8), Size(0, 0), 1.05, 2);//对图片进行多尺度行人检测
	if (found.size() > 0)
	{
		for (int i = 0; i<found.size(); i++)
		{
			CvRect tempRect = cvRect(found[i].x, found[i].y, found[i].width, found[i].height);
			cvRectangle(tmp, cvPoint(tempRect.x, tempRect.y),
			cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(220, 0, 0), 2);
		}
	}
	qImg = new QImage((const unsigned char*)(tmp->imageData), tmp->width, tmp->height, QImage::Format_RGB888);
}
void qttest::selectpic()
{
	PicSelect *picselect = new PicSelect("F:\\96x104\\tmp\\true");
	picselect->show();
}

void qttest::train()
{
	HOGDescriptor hog(Size(96, 104), Size(16, 16), Size(8, 8), Size(8, 8), 18);
	svmTrain(hog,"F:\\96x104\\true","F:\\96x104\\false","svm.xml",ui.plainTextEdit);
	hogTrain("svm.xml","hog.xml",hog,ui.plainTextEdit);
}

void qttest::updateplain()
{
	this->update();
}
