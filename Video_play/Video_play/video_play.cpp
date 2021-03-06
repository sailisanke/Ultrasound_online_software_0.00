#include "video_play.h"
#include "featureparemeters.h"
#include "feature.h"
#include <QFileDialog>
#include <QMessageBox>
#include <time.h>
#include <iostream>
#include <fstream>
#include<vector>

using namespace std;

//vector<vector<double>> fea;
//vector<int>	label;

Video_play::Video_play(QWidget *parent)
	: QMainWindow(parent)
{
	initialPart();
	initialSlots();


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





struct svm_model *model;
struct svm_node  *x;

void Video_play::getFeature(QImage image)
{
	Mat matImage = Mat(image.height(),image.width(),CV_8UC1,(uchar*)image.bits(),image.bytesPerLine());
	uchar seeee0 = matImage.at<uchar>(0,0);
	uchar seeee1 = matImage.at<uchar>(1,1);
	/*Mat matImage2 = cv::Mat(matImage.rows, matImage.cols, CV_8UC1 );*/
// 	ui.dispalyMessage->setText("success!");
// 	ui.dispalyMessage->show();
	Mat imageFeature = getImageFeature(matImage,currentParametersSettings);
// 	vector<double> feature;
// 	feature = vector<double>(imageFeature.reshape(1,1));
// 	double* pimg = (double*)(imageFeature.data);
// 	double aaaa = pimg[0];
// 	double bbbb = (double)imageFeature.data[0];
	
//	double ii = imageFeature.at<double>(0,0);
// 	ofstream fw("feature.txt");
// 	fw.write(imageFeature.data,strlen(imageFeature.data));
//	fw<<imageFeature.data;
// 	file << imageFeature.data;
// 	std::vector<uchar> array(imageFeature.rows*imageFeature.cols);
// 	ofresult << array << std::endl;
	time_t  nowtime = time(NULL);  
	struct tm  *p;
	p = gmtime(&nowtime);  
	char    filename[256] = {0}; 
	sprintf(filename,"%d-%d-%d-%d-%d.txt",1900+p->tm_year,1+p->tm_mon,p->tm_mday,8+p->tm_hour,p->tm_min); 
	writeMatToFile(imageFeature,currentParametersSettings.featureType.toLatin1()+filename);
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
		currentParametersSettings.windowLength =  p.windowLength.toInt();
		currentParametersSettings.channelNumber =  p.channelNumber.toInt();
		currentParametersSettings.overlap =  p.overlap.toInt();
		currentParametersSettings.featureType =  p.featureType;
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

void Video_play::initialPart()
{
	myPlayer = new Player();


	featureDialog = new featureparemeters;
	featureparemeters::featureSettings p = featureDialog->settings();
	currentParametersSettings.channelNumber =  p.channelNumber.toInt();
	currentParametersSettings.windowLength =  p.windowLength.toInt();
	currentParametersSettings.overlap =  p.overlap.toInt();
	currentParametersSettings.featureType =  p.featureType;

}

void Video_play::initialSlots()
{
	QObject::connect(myPlayer, SIGNAL(processedImageSignal(QImage)),this, SLOT(updatePlayerUI(QImage)));
	QObject::connect(myPlayer, SIGNAL(processedImageSignal(QImage)),this, SLOT(getFeature(QImage)));
}

void Video_play::writeMatToFile(cv::Mat& m, const char* filename)
{
	using namespace std;
	ofstream fout(filename,ios_base::app);
	if(!fout)
	{
		cout<<"File Not Opened"<<endl;  return;
	}

	for(int i=0; i<m.rows; i++)
	{
		for(int j=0; j<m.cols; j++)
		{
			double nnn = m.at<double>(i,j);
			fout << nnn << "\t";
		}
		fout<<endl;
	}

	fout.close();
}