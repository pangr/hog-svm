#include "dialog.h"
#include <qfiledialog.h>

dialog::dialog(buttontype bt, QWidget *parent)
{
	ui.setupUi(this);
	this->bt = bt;
	connect(ui.truetb, SIGNAL(clicked()), this, SLOT(getTrueSampath()));
	connect(ui.falsetb, SIGNAL(clicked()), this, SLOT(getFalseSampath()));
	connect(ui.yes, SIGNAL(clicked()), this, SLOT(makeSure()));
	connect(ui.cancel, SIGNAL(clicked()), this, SLOT(candialog()));
}

dialog::~dialog()
{

}

void dialog::getTrueSampath()
{
	QString file_dir;
	file_dir = QFileDialog::getExistingDirectory(this);
	ui.truesampath->setText(file_dir);
}
void dialog::getFalseSampath()
{
	QString file_dir;
	file_dir = QFileDialog::getExistingDirectory(this);
	ui.falsesampath->setText(file_dir);
}

void dialog::makeSure()
{
	if (ui.bin->text().isEmpty() || 
		ui.blockheight->text().isEmpty() ||
		ui.blocksh->text().isEmpty() ||
		ui.blocksw->text().isEmpty() ||
		ui.blockwidth->text().isEmpty() ||
		ui.cellheight->text().isEmpty() || 
		ui.cellwidth->text().isEmpty() || 
		ui.falsesampath->text().isEmpty() || 
		ui.truesampath->text().isEmpty() || 
		ui.winheight->text().isEmpty() || 
		ui.winwidth->text().isEmpty() )
	{
		QMessageBox::information(NULL,QString("提示信息"),QString("训练参数不完整，请完善！"));
	}
	else
	{
		hs.bin = ui.bin->text().toInt();

		hs.winsize = cvSize(ui.winwidth->text().toInt(), ui.winheight->text().toInt());
		hs.blocksize = cvSize(ui.blockwidth->text().toInt(), ui.blockheight->text().toInt());
		hs.blockstr = cvSize(ui.blocksw->text().toInt(), ui.blocksh->text().toInt());
		hs.cellSize = cvSize(ui.cellwidth->text().toInt(), ui.cellheight->text().toInt());
		hs.truepath = ui.truesampath->text().toStdString();
		hs.falsepath = ui.falsesampath->text().toStdString();
		emit sendHS(hs);
		this->close();
	}
}

void dialog::candialog()
{
	this->close();
}