#include "video_play.h"
#include <QFileDialog>
#include <QMessageBox>
Video_play::Video_play(QWidget *parent)
	: QMainWindow(parent)
{
	myPlayer = new Player();
	QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
		this, SLOT(updatePlayerUI(QImage)));
	ui.setupUi(this);
}

Video_play::~Video_play()
{
	delete myPlayer;
}

void Video_play::updatePlayerUI(QImage img)
{
	if (!img.isNull())
	{
		ui.label->setAlignment(Qt::AlignCenter);
		ui.label->setPixmap(QPixmap::fromImage(img).scaled(ui.label->size(),
			Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

void Video_play::on_loadVideo_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this,
		tr("Open Video"), ".",
		tr("Video Files (*.avi *.mpg *.mp4)"));
	if (!filename.isEmpty()){
		if (!myPlayer->loadVideo(filename.toStdString().data()))
		{    
			QMessageBox msgBox;
			msgBox.setText("The selected video could not be opened!");
			msgBox.exec();
		}
	}
}

void Video_play::on_playVideo_clicked()
{
	if (myPlayer->isStop())
	{
		myPlayer->Play();
		ui.playVideo->setText(tr("Stop"));
	}else
	{
		myPlayer->Stop();
		ui.playVideo->setText(tr("Play"));
	}
}
