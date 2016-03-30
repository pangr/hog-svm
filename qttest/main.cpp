#include "mainWin.h"
#include <QtWidgets/QApplication>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp> 
#include <qtextcodec.h>
#include <qtextstream.h>

using namespace cv;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	qttest w;
	w.setWindowTitle("captrue");
	w.show();
	return a.exec();
}
