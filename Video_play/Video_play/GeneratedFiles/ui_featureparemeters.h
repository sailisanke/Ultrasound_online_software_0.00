/********************************************************************************
** Form generated from reading UI file 'featureparemeters.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATUREPAREMETERS_H
#define UI_FEATUREPAREMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_featureparemeters
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *channelNumber;
    QLineEdit *windowLength;
    QLabel *label_2;
    QLineEdit *overlap;
    QLabel *label_4;
    QComboBox *featureType;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *featureparemeters)
    {
        if (featureparemeters->objectName().isEmpty())
            featureparemeters->setObjectName(QStringLiteral("featureparemeters"));
        featureparemeters->resize(455, 311);
        gridLayoutWidget = new QWidget(featureparemeters);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 409, 212));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(200, 30));
        label->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(200, 30));
        label_3->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        channelNumber = new QLineEdit(gridLayoutWidget);
        channelNumber->setObjectName(QStringLiteral("channelNumber"));
        channelNumber->setMinimumSize(QSize(200, 30));
        channelNumber->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(channelNumber, 0, 1, 1, 1);

        windowLength = new QLineEdit(gridLayoutWidget);
        windowLength->setObjectName(QStringLiteral("windowLength"));
        windowLength->setMinimumSize(QSize(200, 30));
        windowLength->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(windowLength, 1, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(200, 30));
        label_2->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        overlap = new QLineEdit(gridLayoutWidget);
        overlap->setObjectName(QStringLiteral("overlap"));
        overlap->setMinimumSize(QSize(200, 30));
        overlap->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(overlap, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(200, 30));
        label_4->setMaximumSize(QSize(16777215, 30));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        featureType = new QComboBox(gridLayoutWidget);
        featureType->setObjectName(QStringLiteral("featureType"));
        featureType->setMinimumSize(QSize(200, 30));
        featureType->setMaximumSize(QSize(200, 30));

        gridLayout_2->addWidget(featureType, 3, 1, 1, 1);

        layoutWidget = new QWidget(featureparemeters);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 240, 411, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        layoutWidget->raise();
        gridLayoutWidget->raise();

        retranslateUi(featureparemeters);
        QObject::connect(buttonBox, SIGNAL(accepted()), featureparemeters, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), featureparemeters, SLOT(reject()));

        QMetaObject::connectSlotsByName(featureparemeters);
    } // setupUi

    void retranslateUi(QDialog *featureparemeters)
    {
        featureparemeters->setWindowTitle(QApplication::translate("featureparemeters", "Feature Paremeters", 0));
        label->setText(QApplication::translate("featureparemeters", "Channel Number:", 0));
        label_3->setText(QApplication::translate("featureparemeters", "Overlap:", 0));
        channelNumber->setText(QApplication::translate("featureparemeters", "5", 0));
        windowLength->setText(QApplication::translate("featureparemeters", "20", 0));
        label_2->setText(QApplication::translate("featureparemeters", "Window Length", 0));
        overlap->setText(QApplication::translate("featureparemeters", "0", 0));
        label_4->setText(QApplication::translate("featureparemeters", "Feature Type:", 0));
        featureType->clear();
        featureType->insertItems(0, QStringList()
         << QApplication::translate("featureparemeters", "fitting coefficient", 0)
         << QApplication::translate("featureparemeters", "mean and variance", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class featureparemeters: public Ui_featureparemeters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATUREPAREMETERS_H
