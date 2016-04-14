#pragma once
#pragma execution_character_set("utf-8")

#ifndef PICSELECT_H
#define PICSELECT_H

#include <QtWidgets/qdialog.h>
#include <Qlabel>
#include <QTimer>
#include <string>
#include <fstream>
#include <io.h>
#include <QtGui\QPaintEvent>  
#include "ui_picSelect.h"

#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;

class PicSelect : public QDialog
{
	Q_OBJECT
public:
	PicSelect(string imgpa,QWidget *parent = 0);
	~PicSelect();
	void showPic(string imgpath);

private:
	Ui::Dialog2 ui;
	vector<string> picpaths;
	long hFile;
	string imgpath;
	struct _finddata_t fileinfo;
	int count;
	QImage *qimg;
	QImage *qimg2;

private slots:
    void nextpicture();
	void priorpicture();
	void delpicture();
};


#endif //PICSELECT_H