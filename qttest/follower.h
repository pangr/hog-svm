#pragma once
#pragma execution_character_set("utf-8")

#ifndef FOLLOER_H
#define FOLLOER_H
#include <cv.h>   
#include <cxcore.h>   
#include <highgui.h>   

#include <cmath>   
#include <vector>   
#include <iostream> 
#include <qplaintextedit.h>

using namespace std;
using namespace cv;


struct node
{
	int x, y;
	bool done = true;
	int dy = 0;
	struct node * next;
};
class kalman
{
public:
	kalman(int winwidth, int winheight,CvRect rect);
	~kalman();
	void kal_predict(int x,int y);
	void updatelist(int x, int y);
	void showlist(bool flag,QPlainTextEdit *&);

private:
	CvKalman * cvkalman;
	CvMat * process_noise;
	CvMat * measurement;
	CvRNG rng;
	IplImage * img;
	CvRect rect;
	node * nl;
	int sum;
	int num;
};
void initlinklist(node *&L);
void insertNode(node *&L, int x, int y);
node * deleteNode(node *&L, node *p);


#endif // !FOLLOER_H
