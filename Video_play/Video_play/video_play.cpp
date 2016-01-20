#include "video_play.h"
#include "featureparemeters.h"
#include <QFileDialog>
#include <QMessageBox>
Video_play::Video_play(QWidget *parent)
	: QMainWindow(parent)
{
	myPlayer = new Player();
	featureDialog = new featureparemeters;


	QObject::connect(myPlayer, SIGNAL(processedImageSignal(QImage)),this, SLOT(updatePlayerUI(QImage)));
	QObject::connect(myPlayer, SIGNAL(processedImageSignal(QImage)),this, SLOT(getFeature(QImage)));


	ui.setupUi(this);
	
	
}

Video_play::~Video_play()
{
	delete myPlayer;
	delete featureDialog;
}

void Video_play::updatePlayerUI(QImage img)
{
	if (!img.isNull())
	{
		ui.label->setAlignment(Qt::AlignCenter);
		ui.label->setPixmap(QPixmap::fromImage(img).scaled(ui.label->size(),
			Qt::KeepAspectRatio, Qt::FastTransformation));
		/*ui.label->show();*/
	}
}

void Video_play::getFeature(QImage image)
{
	Mat matImage = Mat(image.height(),image.width(),CV_8UC1,(uchar*)image.bits(),image.bytesPerLine());
	/*Mat matImage2 = cv::Mat(matImage.rows, matImage.cols, CV_8UC1 );*/
	ui.dispalyMessage->setText("success!");
	ui.dispalyMessage->show();
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

void Video_play::on_actionFeature_triggered()
{
	
	if (featureDialog->exec() == QDialog::Accepted)
	{
		featureparemeters::featureSettings p = featureDialog->settings();
// 		currentParametersSettings.channelNumber =  featureDialog.getchannelNumber();
// 		currentParametersSettings.windowLength =  featureDialog.getwindowLength();
// 		currentParametersSettings.overlap =  featureDialog.getoverlap();
// 		currentParametersSettings.featureType =  featureDialog.getfeatureType();
		/*ui.dispalyMessage->setText(currentParametersSettings.featureType+currentParametersSettings.channelNumber+currentParametersSettings.windowLength+currentParametersSettings.overlap);*/
// 		ui.dispalyMessage->setText(p.featureType+p.channelNumber+p.windowLength+p.overlap);
// 		ui.dispalyMessage->hide();
	}
	 // 模态对话框
// 	
// 	featureparemeters *featureDialog = new featureparemeters;
//  featureDialog->setAttribute(Qt::WA_DeleteOnClose); // 释放内存
// 	featureDialog->show(); // 非模态对话框

}
