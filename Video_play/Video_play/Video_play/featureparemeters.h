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
	int 

private:
	Ui::featureparemeters ui;
};

#endif // FEATUREPAREMETERS_H
