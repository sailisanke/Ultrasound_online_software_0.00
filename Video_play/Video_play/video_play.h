#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_video_play.h"
#include <player.h>
#include <iostream>
#include <fstream>

class featureparemeters;


class Video_play : public QMainWindow
{
	Q_OBJECT

public:
	Video_play(QWidget *parent = 0);
	~Video_play();
	struct parametersSettings 
	{
		QString featureType;
		int channelNumber;
		int windowLength;
		int overlap;
	};
	featureparemeters *featureDialog;
	

private:
	Ui::Video_playClass ui;
	Player* myPlayer;
	parametersSettings currentParametersSettings;

private slots:
	void updatePlayerUI(QImage img);
	void getFeature(QImage);
	void on_loadVideo_clicked();
	void on_playVideo_clicked();
	void on_actionFeature_triggered();
	void initialPart();
	void initialSlots();
	void writeMatToFile(cv::Mat& m, const char* filename);
};

#endif // VIDEO_PLAY_H
