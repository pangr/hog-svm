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

int a[17] = { 2300, 4620, 5589, 11000, 13442, 16670, 18799, 21164, 22978, 24945, 25841, 26690, 30147, 31299, 32700, 35312, 36780 };
int b[17] = { 2400, 4815, 5790, 11291, 13840, 17203, 19430, 21850, 23380, 25348, 26057, 26976, 30418, 31391, 32970, 35485, 37393 };
int frame_out = 0;
int j = 0;

qttest::qttest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.plainTextEdit->setReadOnly(true);
	timer = new QTimer(this);
	capture = NULL;
	qImg = NULL;
	ispause = true;
	inRect = cvRect(10, 85, 310, 135);
	outRect = cvRect(375, 85, 310, 135);

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
	hog = HOGDescriptor(Size(96, 104), Size(16, 16), Size(8, 8), Size(8, 8), 18);
	hog.load("hog.xml");
	QString file_full;
	char *fp;
	file_full = QFileDialog::getOpenFileName(this);
	std::string str = file_full.toStdString();
	const char * fpp = str.c_str();
	ispause = false;
	kal = new kalman(350, 287, cvRect(10, 85, 310, 135));
	if (*fpp != NULL)
	{
		capture = cvCaptureFromAVI(fpp);
		this->resize((int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH),
			          (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT));
		if (capture)
		{
			cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES,a[0]);
			frame_out = a[0];
			frame = cvQueryFrame(capture);
			if (frame)
			{
				dopicture(hog);
				timer->setInterval(30);
				connect(timer, SIGNAL(timeout()), this, SLOT(nextframe()));
				timer->start();
			}
		}
	}
	
}
void qttest::pictureCapture()
{
	timer->stop();
	QString file_full;
	char *fp;
	file_full = QFileDialog::getOpenFileName(this);
	std::string str = file_full.toStdString();
	const char * fpp = str.c_str();
	//qDebug("%s\n", fpp);
	aviplayer *aper = new aviplayer;
	aper->playavi(fpp,"F:\\tmp2");
}

void qttest::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	if (qImg != NULL)
	{
		painter.drawImage(QPoint(210, 20), *qImg);
	}

}
	

void qttest::nextframe()
{
	start = clock();
	if (frame_out != b[j])
	{
		frame = cvQueryFrame(capture);
		dopicture(hog);
		this->update();
		frame_out++;
	}
	else
	{
		j++;
		cvSetCaptureProperty(capture ,CV_CAP_PROP_POS_FRAMES ,a[j]);
		frame_out = a[j];
	}
	finish = clock();
	//qDebug("%f\n", finish - start);
}

void qttest::dopicture(HOGDescriptor &hog)
{

	cvSetImageROI(frame, inRect);
	hog.detectMultiScale(frame, fod, 0, Size(8, 8), Size(32, 32), 1.05, 2);//对图片进行多尺度行人检测
	cvResetImageROI(frame);
	cvRectangle(frame, cvPoint(inRect.x, inRect.y), cvPoint(inRect.x + inRect.width, inRect.y + inRect.height), CV_RGB(0, 0, 255), 1);
	this->resize(frame->width + 220, frame->height + 100);

	if (fod.size() > 0)
	{
		for (int i = 0; i<fod.size(); i++)
		{
			//qDebug("%f,%f", fod[i].x + 10 + (fod[i].width*0.5), fod[i].y + 85 + (fod[i].height*0.5));
			ui.plainTextEdit->appendPlainText(QString::number(fod[i].x + 10 + (fod[i].width*0.5)) + "," + QString::number(fod[i].y + 85 + (fod[i].height*0.5)));
			kal->updatelist(fod[i].x + 10 + (fod[i].width*0.5), fod[i].y + 85 + (fod[i].height*0.5));
			CvRect tempRect = cvRect(fod[i].x + inRect.x, fod[i].y + inRect.y, fod[i].width, fod[i].height);
			cvRectangle(frame, cvPoint(tempRect.x, tempRect.y),
			cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(0, 0, 220), 2);
		}
		kal->showlist(true,ui.plainTextEdit);
	}
	else
	{
		kal->showlist(false,ui.plainTextEdit);
	}
	cvSetImageROI(frame, outRect);
	hog.detectMultiScale(frame, fod, 0, Size(8, 8), Size(32, 32), 1.05, 2);//对图片进行多尺度行人检测
	cvResetImageROI(frame);
	cvRectangle(frame, cvPoint(outRect.x, outRect.y), cvPoint(outRect.x + outRect.width, outRect.y + outRect.height), CV_RGB(0, 0, 255), 1);
	if (fod.size() > 0)
	{
		for (int i = 0; i<fod.size(); i++)
		{
			//qDebug("%f,%f", fod[i].x + 375 + (fod[i].width*0.5), fod[i].y + 85 + (fod[i].height*0.5));
			ui.plainTextEdit->appendPlainText(QString::number(fod[i].x + 375 + (fod[i].width*0.5)) + "," + QString::number(fod[i].y + 85 + (fod[i].height*0.5)));
			kal->updatelist(fod[i].x + 375 + (fod[i].width*0.5), fod[i].y + 85 + (fod[i].height*0.5));
			CvRect tempRect = cvRect(fod[i].x + outRect.x, fod[i].y + outRect.y, fod[i].width, fod[i].height);
			cvRectangle(frame, cvPoint(tempRect.x, tempRect.y),
			cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(0, 0, 220), 2);
		}
		kal->showlist(true,ui.plainTextEdit);
	}
	else
	{
		kal->showlist(false,ui.plainTextEdit);
	}
	cvCvtColor(frame, frame, CV_BGR2RGB);
	qImg = new QImage((const unsigned char*)(frame->imageData), frame->width, frame->height, QImage::Format_RGB888);
}
void qttest::selectpic()
{
	PicSelect *picselect = new PicSelect("F:\\96x104\\true");
	picselect->show();
}

void qttest::train()
{
	dialog * dia = new dialog(TRAIN);
	connect(dia, SIGNAL(sendHS(hogSize)), this, SLOT(receiveData(hogSize)));
	dia->show();
}

void qttest::receiveData(hogSize hs)
{
	HOGDescriptor hog(hs.winsize, hs.blocksize, hs.blockstr, hs.cellSize, hs.bin);
	svmTrain(hog, hs.truepath, hs.falsepath, "svm.xml", ui.plainTextEdit);
	hogTrain("svm.xml", "hog.xml", hog, ui.plainTextEdit);
}

void qttest::updateplain()
{
	this->update();
}

void qttest::keyPressEvent(QKeyEvent *k)
{
	if (k->key() == Qt::Key_A)
	{
		if (ispause)
		{
			timer->start();
			ispause = false;
		}
		else
		{
			timer->stop();
			ispause = true;
		}
	}
	if (k->key() == Qt::Key_Escape)
	{
		this->resize(193,392);
		timer->stop();
	}
}

