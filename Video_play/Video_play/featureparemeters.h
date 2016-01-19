#ifndef FEATUREPAREMETERS_H
#define FEATUREPAREMETERS_H

#include <QDialog>
#include "ui_featureparemeters.h"

class featureparemeters : public QDialog, public Ui::featureparemeters
{
	Q_OBJECT

public:
	featureparemeters(QWidget *parent = 0);
	~featureparemeters();
	struct featureSettings {
		QString featureType;
		QString channelNumber;
		QString windowLength;
		QString overlap;
	};
	QString getfeatureType();
	QString getchannelNumber();
	QString getwindowLength();
	QString getoverlap();


private:
	Ui::featureparemeters ui;
	featureSettings currentFeatureSettings;
	
};

#endif // FEATUREPAREMETERS_H
