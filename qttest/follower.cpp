#include "follower.h"
#include <qdebug.h>

kalman::kalman(int winwidth, int winheight,CvRect rect)
{
	cvkalman = cvCreateKalman(4, 2, 0);
	process_noise = cvCreateMat(4, 1, CV_32FC1);
	measurement = cvCreateMat(2, 1, CV_32FC1);
	rng = cvRNG(-1);
	float A[4][4] = {
		1, 0, 1, 0,
		0, 1, 0, 1,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
	this->rect = rect;
	memcpy(cvkalman->transition_matrix->data.fl,A,sizeof(A));
	cvSetIdentity(cvkalman->measurement_matrix,cvRealScalar(1));
	cvSetIdentity(cvkalman->process_noise_cov,cvRealScalar(1e-5));
	cvSetIdentity(cvkalman->measurement_noise_cov, cvRealScalar(1e-1));
	cvSetIdentity(cvkalman->error_cov_post, cvRealScalar(1));
	cvRandArr(&rng, cvkalman->state_post, CV_RAND_UNI, cvRealScalar(0), cvRealScalar(winheight>winwidth ? winwidth : winheight));
	//cvNamedWindow("kalman",1);
	img = cvCreateImage(cvSize(winwidth, winheight), 8, 3);
	cvSet(img, cvScalar(255, 255, 255, 0));
	cvRectangle(img, cvPoint(rect.x, rect.y), cvPoint(rect.x+rect.width, rect.y+rect.height), cvScalar(255, 0, 0));
	//cvShowImage("kalman",img);
	initlinklist(nl);
	sum = 0;
	num = 0;
}

kalman::~kalman()
{
}

void kalman::kal_predict(int x,int y)
{
	int i = 0;

		const CvMat * prediction = cvKalmanPredict(cvkalman, 0);
		CvPoint predict_pt = cvPoint((int)prediction->data.fl[0], (int)prediction->data.fl[1]);

		measurement->data.fl[0] = (float)x;
		measurement->data.fl[1] = (float)y;

		const CvMat * correct = cvKalmanCorrect(cvkalman, measurement);
		cvSet(img, cvScalar(255, 255, 255, 0));
		cvRectangle(img, cvPoint(rect.x, rect.y), cvPoint(rect.x + rect.width, rect.y + rect.height), cvScalar(255, 0, 0));
		cvCircle(img, predict_pt, 5, CV_RGB(0, 255, 0), 3);
		cvCircle(img, cvPoint(x, y), 5, CV_RGB(255, 0, 0), 3);
		cvCircle(img, cvPoint(correct->data.fl[0], correct->data.fl[1]), 5, CV_RGB(0, 0, 255), 3);
		//cvShowImage("kalman", img);
		i++;
}

void kalman::updatelist(int x, int y)
{
	node * p = nl->next;
	bool existud = false;
 	while (p)
	{
		if ((p->x - x)*(p->x - x) <= 3000 && (p->y - y)*(p->y - y) <= 3750)
		{
			p->dy = p->dy + p->y - y;
			p->x = x;
			p->y = y;
			p->done = true;
			existud = true;
			break;
		}
		p = p->next;
	}
	if (!existud && x != 0 && y != 0)
	{
		insertNode(nl, x, y);
	}
}
void kalman::showlist(bool flag ,QPlainTextEdit *&plain)
{
	cvSet(img, cvScalar(255, 255, 255, 0));
	cvRectangle(img, cvPoint(rect.x, rect.y), cvPoint(rect.x + rect.width, rect.y + rect.height), cvScalar(255, 0, 0));

	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1, 8);
	if (nl->next)
	{
		node * p = nl->next;
		if (num >= 5 || flag)
		{
			while (p)
			{
				if (p->done)
				{
					cvCircle(img, cvPoint(p->x, p->y), 5, CV_RGB(255, 0, 0), 3);
 					p->done = false;
					p = p->next;
				}
				else
				{
					qDebug("dy:%d", p->dy);
					
					if (p->dy >= 10)
					{
						sum = sum - 1;
						qDebug("The Number : %d", sum);
						cvPutText(img, sum + "", cvPoint(0, 20), &font, cvScalar(0, 0, 255));

					}
					else if (p->dy <= -10)
					{
						sum++;
						qDebug("The Number : %d", sum);
						cvPutText(img, sum + "", cvPoint(0, 20), &font, cvScalar(0, 0, 255));
					}
					plain->appendPlainText("The Number :"+QString::number(sum));
					p = deleteNode(nl, p);
				}

			}
			num = 0;
		}
		else
		{
			num++;
		}
	}
	//cvShowImage("kalman",img);
 }

void initlinklist(node *&L)
{
	L = new node; 
	L->next = NULL;
}
void insertNode(node *&L, int x, int y)
{
	if (L == NULL)
	{
		return;
	}
	node * p = new node;
	p->x = x;
	p->y = y;
	p->done = true;
	p->next = L->next;
	L->next = p;
}
node * deleteNode(node *&L, node *p)
{
	if (L == NULL)
	{
		return NULL;
	}
	node * q = L;
	while (q->next != p)
	{
		q = q->next;
	}
		q->next = p->next;
		delete p;
	return q->next;
}