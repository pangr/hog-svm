#pragma once
#pragma execution_character_set("utf-8")

#ifndef DIALOG_H
#define DIALOG_H

#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qmessagebox.h>

#include <opencv2\opencv.hpp>
#include "ui_dialog.h"

using namespace cv;

enum buttontype
{
	LOADAVI,
	CAPPIC,
	TRAIN
};
struct hogSize
{
	CvSize winsize;
	CvSize cellSize;
	CvSize blocksize;
	CvSize blockstr;
	int bin;
	std::string truepath;
	std::string falsepath;
};

class dialog : public QDialog
{
	Q_OBJECT
public:
	dialog(buttontype bt, QWidget *parent = 0);
	~dialog();
	hogSize getHS(){ return hs; }

private:
	buttontype bt;
	Ui::Dialog ui;
	hogSize hs;
signals:
	void sendHS(hogSize);

private slots:
    void getTrueSampath();
	void getFalseSampath();
	void makeSure();
	void candialog();
};


#endif // !DIALOG_H
