#include "player.h"

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
		framerate = (int) capture.get(CAP_PROP_FPS);
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
		if (!capture.read(frame))
		{
			stop = true;
		}
		if (frame.channels() == 3)
		{
			cv::cvtColor(frame,RGBframe,COLOR_BGR2RGB);
			img = QImage( (const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, RGBframe.step, QImage::Format_RGB888);
		}
		else
		{
			img = QImage( (const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, RGBframe.step, QImage::Format_Indexed8);
		}
		emit processedImage(img);
		this->msleep(delay);
	}
}

// void Player::msleep11(int ms)
// {
// 	sleep(uint(ms));
// }

