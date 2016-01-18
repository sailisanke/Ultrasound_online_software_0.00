#ifndef PLAYER_H
#define PLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
/*#include <string>*/
using namespace cv;
class Player : public QThread
{
	Q_OBJECT

public:
	Player(QObject *parent = 0);
	~Player();
	bool loadVideo(String filename);
	void Play();
	void Stop();
	bool isStop() const;

private:
	bool stop;
	QMutex mutex;
	QWaitCondition condition;
	Mat frame;
	int framerate;
	VideoCapture capture;
	Mat RGBframe;
	QImage img;

signals:
	void processedImage(const QImage &Image);

protected:
	void run();
	/*void msleep11(int ms);*/
	
};

#endif // PLAYER_H
