#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H

#include <QtWidgets/QMainWindow>
#include "ui_video_play.h"
#include <player.h>

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
		QString channelNumber;
		QString windowLength;
		QString overlap;
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

};

#endif // VIDEO_PLAY_H
