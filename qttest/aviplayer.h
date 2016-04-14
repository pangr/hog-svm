#pragma once
#pragma execution_character_set("utf-8")

#ifndef AVIPLATER_H
#define AVIPLATER_H

#include <opencv2\opencv.hpp>
#include <trainer.h>
#include <fstream>
#include <io.h>
#include <string>
#include <follower.h>


class aviplayer
{
public:
	aviplayer();
	~aviplayer();
	void playavi(const char* avipath, char * savepath);
	void dopicture(char* loadpath, char * savepath);
public:
	CvCapture *capture;
	IplImage *frame;
	IplImage *img;
	CvPoint pt,pt1, pt2;
	int frame_out;
	int g_slider_pos;
	int count_tmp;
	bool close;
	int framecount;
	int speed;
	int rad;
	bool is_select;
	vector<Rect> found;
	HOGDescriptor hog;
	kalman * kal;
	HOGDescriptor hog2;
private:
    void cvMouseCallback(int mouseEvent, int x, int y ,int flags);
	friend void on_Mouse(int mouseEvent, int x, int y, int flags, void* param);
	void cvchanged(int pos);
	friend void on_change(int pos,void* userdata);
	void capPicture(IplImage *frame,char* savepath);

};

#endif //AVIPLATER_H