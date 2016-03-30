#include "picSelect.h"

#include <qpainter.h>
#include <qdebug.h>
#include <stdio.h>

PicSelect::PicSelect(string imgpa, QWidget * parent) 
{
	ui.setupUi(this);
	connect(ui.next, SIGNAL(clicked()), this, SLOT(nextpicture()));
	connect(ui.prior, SIGNAL(clicked()), this, SLOT(priorpicture()));
	connect(ui.delete_2, SIGNAL(clicked()), this, SLOT(delpicture()));
	hFile = 0;
	if ((hFile = _findfirst(imgpath.assign(imgpa).append("\\*").c_str(),&fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{

			}
			else
			{
				picpaths.push_back(imgpath.assign(imgpa).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
	}
	count = 0;
	if (picpaths.size() != 0 && picpaths.size() != count)
	{
		qDebug() << picpaths[count].c_str()<< endl;
		showPic(picpaths[count]);
		count++;
	}
	
}
PicSelect::~PicSelect()
{
 
}

void PicSelect::nextpicture()
{
	if (picpaths.size() != 0 && picpaths.size() != count)
	{
		qDebug() << picpaths[count].c_str() << endl;
		showPic(picpaths[count]);
		count++;
	}
	
}

void PicSelect::priorpicture()
{
	if (picpaths.size() != 0 && count>=2)
	{
		count--;
		showPic(picpaths[count-1]);
	}
}

void PicSelect::delpicture()
{
	if (count > 0)
	{
		count--;
		if (remove(picpaths[count].c_str()) == 0)
		{
			picpaths.erase(picpaths.begin() + count);
			nextpicture();
		}
	}
}

void PicSelect::showPic(string imgpath)
{
	IplImage *img = cvLoadImage(imgpath.c_str());
	qimg2 = new QImage((const unsigned char*)(img->imageData),img->width,img->height,QImage::Format_RGB888);
	ui.imagelabel_2->setPixmap(QPixmap::fromImage(*qimg2));
	ui.imagelabel_2->resize(ui.imagelabel_2->pixmap()->size());
	cvRectangle(img,cvPoint(0,0),cvPoint(96,104),cvScalar(255,255,255));
	cvCircle(img, cvPoint(48, 52), 36, cvScalar(255, 255, 255));
    qimg = new QImage((const unsigned char*)(img->imageData), img->width, img->height, QImage::Format_RGB888);
	ui.imagelabel->setPixmap(QPixmap::fromImage(*qimg));
	ui.imagelabel->resize(ui.imagelabel->pixmap()->size());
	int pos = imgpath.find_last_of('\\');
	string s(imgpath.substr(pos + 1));
	ui.name->setText(s.c_str());
}
