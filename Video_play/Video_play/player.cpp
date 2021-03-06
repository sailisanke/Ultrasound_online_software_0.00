#include "player.h"
#include <opencv/cv.h>
Player::Player(QObject *parent)
	: QThread(parent)
{
	stop = true;
}

Player::~Player()
{
	mutex.lock();
	stop = true;
	capture.release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}

bool Player::loadVideo(String filename)
{
	capture.open(filename);
	if (capture.isOpened())
	{
		framerate = (int) capture.get(CV_CAP_PROP_FPS);
		return true;
	}
	else
		return false;
}

void Player::Play()
{
	if (!isRunning())
	{
		if (isStop())
		{
			stop = false;
		}
		start(LowPriority);
	}
}

void Player::Stop()
{
	stop = true;
}

bool Player::isStop() const
{
	return this->stop;
}

void Player::run()
{
	int delay = (1000/framerate);
	while(!stop){
		if (!capture.read(frame0))
		{
			stop = true;
		}
		else
		{
			if (frame0.channels() == 3)
			{
				frame = frame0(Range(119,500),Range(285,800));
				//frame = frame0;

				//cv::cvtColor(frame,frame,CV_BGR2RGB);
				cv::cvtColor(frame,RGBframe,CV_BGR2GRAY);
				img = QImage( (const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, RGBframe.step, QImage::Format_Indexed8);
				/*cv::cvtColor(frame,RGBframe,COLOR_BGR2RGB);*/
				/*img = QImage( (const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, RGBframe.step, QImage::Format_RGB888);*/
			}
			else
			{
				/*emit extractFeatureSignal(frame);*/
				/*frame = frame(Range(119,500),Range(285,800));*/
				img = QImage( (const unsigned char*)(frame.data), frame.cols, frame.rows, frame.step, QImage::Format_Indexed8);
			}
			/*emit extractFeatureSignal(img);*/
			emit processedImageSignal(img);
			this->msleep(delay);
		}
		}
		
}

