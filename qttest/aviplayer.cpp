#include "aviplayer.h"

#include <qdebug.h>
#include <qwidget.h>
#include <detect.h>

using namespace std;

aviplayer::aviplayer()
{
	capture = NULL;
	count_tmp = 0;
	close = false;
	g_slider_pos = 0;
	frame_out = 0;
	pt = cvPoint(0, 0);
	pt1 = cvPoint(0, 0);
	pt2 = cvPoint(0, 0);
	count_tmp = 841;
	speed = 33;
	rad = 0;
	is_select = false;
}
aviplayer::~aviplayer()
{
	cvReleaseCapture(&capture);
	cvDestroyWindow("AVI player");
}

void aviplayer::playavi(char * avipath,char * savepath)
{
	hog = HOGDescriptor(Size(96, 104), Size(16, 16), Size(8, 8), Size(8, 8), 18);
	//hog2 = HOGDescriptor(Size(192, 32), Size(16, 16), Size(8, 8), Size(8, 8), 18);
	hog.load("hog.xml");
	capture = cvCaptureFromAVI(avipath);
	cvNamedWindow("AVI player",1);
	cvSetMouseCallback("AVI player", on_Mouse, this);
	framecount = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	if (framecount > 0)
	{
	    cvCreateTrackbar2("Position", "AVI player", &g_slider_pos, framecount, on_change,this);
	}
	bool suspend = false;
	long num = 0;
	char tmpfile[10] = { '\0' };
	while (!suspend)
	{

		while ((frame = cvQueryFrame(capture)) != NULL)
		{
			cvSetImageROI(frame, cvRect(10, 85, 310, 135));
			IplImage * img = cvCreateImage(cvSize(310, 135), frame->depth, frame->nChannels);
			cvCopy(frame, img);
			cvResetImageROI(frame);
			IplImage * imgtmp = cvCloneImage(frame);
			cvRectangle(imgtmp, cvPoint(10, 85), cvPoint(320, 220), CV_RGB(0, 0, 255), 1);
			if (num % 2 == 0)
			{
				hog.detectMultiScale(img, found, 0, Size(8, 8), Size(32, 32), 1.05, 2);
			}

			if (found.size() > 0)
			{
				for (int i = 0; i<found.size(); i++)
				{
					CvRect tempRect = cvRect(found[i].x + 10, found[i].y + 85, found[i].width, found[i].height);
					if (num % 5 == 0)
					{
						/*cvSetImageROI(frame, tempRect);
						sprintf(tmpfile, "%s//false%d.jpg", savepath, count_tmp);
						cvSaveImage(tmpfile, frame);
						cvResetImageROI(frame);
						++count_tmp;*/
					}
					cvRectangle(imgtmp, cvPoint(tempRect.x, tempRect.y),
						cvPoint(tempRect.x + tempRect.width, tempRect.y + tempRect.height), CV_RGB(220, 0, 0), 2);
				}
			}
			num++;
			cvShowImage("AVI player", imgtmp);
			cvSetTrackbarPos("Position", "AVI player", frame_out);
			frame_out++;
			cvReleaseImage(&img);
			cvReleaseImage(&imgtmp);
			char c = cvWaitKey(speed);
			if (c == ' ')
			{
				suspend = true;
				break;
			}
			else if (c == 27)
			{
				close = true;
				break;
			}
			else if (c == 'j')
			{
				speed += 3;
				c = cvWaitKey(speed);
			}
			else if (c == 'l')
			{
				speed -= 3;
				c = cvWaitKey(speed);
			}
		}
		if (close)
		{
			cvReleaseCapture(&capture);
			cvDestroyWindow("AVI player");
			break;
		}
		if (suspend)
		{
			capPicture(frame,savepath);
			suspend = false;
		}
		else
		{
			cvReleaseCapture(&capture);
			cvDestroyWindow("AVI player");
			break;
		}
	}
	
}
void aviplayer::capPicture(IplImage* frame,char * savepath)
{

	IplImage* img, *imgframe;
	IplImage* min[4];
	CvSize cvsize[4];
	cvSetImageROI(frame, cvRect(0,0,frame->width,frame->height*0.5));
	for (int i = 0; i < 4; i++)
	{
		cvsize[0].width = frame->width * (1-(float)(i+2)/10.0);
		cvsize[0].height = frame->height * (1 - (float)(i+2) / 10.0) *0.5;
		min[i] = cvCreateImage(cvsize[0], frame->depth, frame->nChannels);
		cvResize(frame, min[i], CV_INTER_AREA);
	}
	img = cvCreateImage(cvSize(min[0]->width*2, min[0]->height*2), frame->depth, frame->nChannels);

	int m = 0;
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		cvSetImageROI(img, cvRect(m, n, min[i]->width, min[i]->height));
		cvResize(min[i],img);
		cvResetImageROI(img);
		if (i == 0)
		{
			m = m + min[0]->width;
		}
		if (i == 1)
		{
			n = n + min[0]->height;
		}
		if (i == 2)
		{
			m = m - min[0]->width;
		}
	}
	imgframe = cvCloneImage(img);
	cvNamedWindow("AVI player2", 1);
	cvSetMouseCallback("AVI player2", on_Mouse, this);

	while (true)
	{
		    cvCopy(imgframe, img);
		    cvRectangle(img, pt1, pt2, cvScalar(255, 255, 255));
		    cvCircle(img, pt, rad, cvScalar(255, 255, 255));
			cvShowImage("AVI player2", img);

			char tmpfile[100] = { '\0' };
			char key = cvWaitKey(10);
			if (key == '\r')
			{
				cvSetImageROI(imgframe, cvRect(pt1.x, pt1.y, std::abs(pt2.x - pt1.x), std::abs(pt2.y - pt1.y)));
				sprintf(tmpfile, "%s//true%d.jpg", savepath, count_tmp);
				cvSaveImage(tmpfile, imgframe);
				cvResetImageROI(imgframe);
				++count_tmp;
			}

			if (key == ' ')
			{
				cvDestroyWindow("AVI player2");
				for (int i = 0; i < 3; i++)
				{
					cvReleaseImage(&min[i]);
				}
				rad = 0;
				pt1 = pt2;
				break;
			}
		
	}
}
void aviplayer::cvMouseCallback(int mouseEvent, int x, int y, int flags)
{
	switch (mouseEvent)
	{
	case CV_EVENT_LBUTTONDOWN:
		pt1.x = cvPoint(x, y).x - 32;
		pt1.y = cvPoint(x, y).y - 32;
		pt2.x = cvPoint(x, y).x + 32;
		pt2.y = cvPoint(x, y).y + 32;
		pt = cvPoint(x, y);
		rad = 30;
		is_select = true;
		break;
	case CV_EVENT_MOUSEMOVE:
		if (is_select)
		{
			pt = cvPoint(x, y);
			rad = 30;
			pt1.x = cvPoint(x, y).x - 32;
			pt1.y = cvPoint(x, y).y - 32;
			pt2.x = cvPoint(x, y).x + 32;
			pt2.y = cvPoint(x, y).y + 32;
		}
		break;
	case CV_EVENT_LBUTTONUP:
		if (is_select)
		{
			is_select = false;
			pt = cvPoint(x, y);
			rad = 30;
			pt1.x = cvPoint(x, y).x - 32;
			pt1.y = cvPoint(x, y).y - 32;
			pt2.x = cvPoint(x, y).x + 32;
			pt2.y = cvPoint(x, y).y + 32;
		}
		break;
	default:
		break;
	}

	return;
}
void aviplayer::cvchanged(int pos)
{
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
	frame_out = pos;
}

void on_Mouse(int mouseEvent, int x, int y, int flags, void* param)
{
	aviplayer * aviplay = static_cast<aviplayer*>(param);
	if (aviplay)
	{
		aviplay->cvMouseCallback(mouseEvent, x, y,flags);
	}
}

void on_change(int pos, void* param)
{
	aviplayer * aviplay = static_cast<aviplayer*>(param);
	if (aviplay)
	{
		aviplay->cvchanged(pos);
	}
}

void aviplayer::dopicture(char * loadpath,char * savepath)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string imgpath;
	cvNamedWindow("a",1);
	cvSetMouseCallback("a", on_Mouse, this);
	bool done = false;
	if ((hFile = _findfirst(imgpath.assign(loadpath).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{

			}
			else
			{
				img = cvLoadImage(imgpath.assign(loadpath).append("\\").append(fileinfo.name).c_str());
				IplImage * imgtmp = cvCreateImage(cvSize(img->width*0.9,img->height*0.9),img->depth,img->nChannels);
				cvResize(img, imgtmp, CV_INTER_AREA);
				IplImage * imgtmp2 = cvCreateImage(cvSize(img->width*0.9, img->height*0.9), img->depth, img->nChannels);
				while (true)
				{
					cvCopy(imgtmp,imgtmp2);
					cvRectangle(imgtmp2, pt1, pt2, cvScalar(255, 255, 255));
					cvCircle(imgtmp2, pt,rad, cvScalar(255, 255, 255));
					cvShowImage("a",imgtmp2);
					char tmpfile[100] = { '\0' };
					char key = cvWaitKey(10);
					if (key == '\r')
					{
						cvSetImageROI(imgtmp, cvRect(pt1.x, pt1.y, std::abs(pt2.x - pt1.x), std::abs(pt2.y - pt1.y)));
						sprintf(tmpfile, "%s//%s", savepath, fileinfo.name);
						cvSaveImage(tmpfile, imgtmp);
						cvResetImageROI(imgtmp);
						break;
					}
					if (key == ' ')
					{
						break;
					}
					if (key == 27)
					{
						done = true;
						break;
					}
				}
				if (done)
				{
					break;
				}
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		cvReleaseImage(&img);
		cvDestroyWindow("a");
	}
}

