#include "featureparemeters.h"

featureparemeters::featureparemeters(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	updateSettings();
	connect(ui.buttonBox,SIGNAL(accepted()),this,SLOT(okButton()));
	connect(ui.buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
	
}

featureparemeters::~featureparemeters()
{

}

// QString featureparemeters::getfeatureType()
// {
// 	return ui.featureType->currentText();
// }
// 
// QString featureparemeters::getchannelNumber()
// {
// 	return ui.channelNumber->text();
// }
// 
// QString featureparemeters::getwindowLength()
// {
// 	return ui.windowLength->text();
// }
// 
// QString featureparemeters::getoverlap()
// {
// 	return ui.overlap->text();
// }

void featureparemeters::okButton()
{
	updateSettings();
	accept();
}

void featureparemeters::updateSettings()
{
	currentFeatureSettings.channelNumber = ui.channelNumber->text();
	currentFeatureSettings.windowLength = ui.windowLength->text();
	currentFeatureSettings.overlap = ui.overlap->text();
	currentFeatureSettings.featureType = ui.featureType->currentText();
}

featureparemeters::featureSettings featureparemeters::settings() const
{
	return currentFeatureSettings;
}
