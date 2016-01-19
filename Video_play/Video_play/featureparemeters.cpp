#include "featureparemeters.h"

featureparemeters::featureparemeters(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

featureparemeters::~featureparemeters()
{

}

QString featureparemeters::getfeatureType()
{
	return ui.featureType->currentText();
}

QString featureparemeters::getchannelNumber()
{
	return ui.channelNumber->text();
}

QString featureparemeters::getwindowLength()
{
	return ui.windowLength->text();
}

QString featureparemeters::getoverlap()
{
	return ui.overlap->text();
}
