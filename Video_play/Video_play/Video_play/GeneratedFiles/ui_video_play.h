/********************************************************************************
** Form generated from reading UI file 'video_play.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_PLAY_H
#define UI_VIDEO_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Video_playClass
{
public:
    QAction *actionFeature;
    QWidget *centralWidget;
    QPushButton *loadVideo;
    QPushButton *playVideo;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuSetting;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Video_playClass)
    {
        if (Video_playClass->objectName().isEmpty())
            Video_playClass->setObjectName(QStringLiteral("Video_playClass"));
        Video_playClass->resize(1128, 749);
        actionFeature = new QAction(Video_playClass);
        actionFeature->setObjectName(QStringLiteral("actionFeature"));
        centralWidget = new QWidget(Video_playClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loadVideo = new QPushButton(centralWidget);
        loadVideo->setObjectName(QStringLiteral("loadVideo"));
        loadVideo->setGeometry(QRect(860, 130, 93, 28));
        playVideo = new QPushButton(centralWidget);
        playVideo->setObjectName(QStringLiteral("playVideo"));
        playVideo->setGeometry(QRect(860, 350, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 70, 591, 361));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QStringLiteral("Background-color: #000;"));
        Video_playClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Video_playClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1128, 26));
        menuSetting = new QMenu(menuBar);
        menuSetting->setObjectName(QStringLiteral("menuSetting"));
        Video_playClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Video_playClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Video_playClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Video_playClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Video_playClass->setStatusBar(statusBar);

        menuBar->addAction(menuSetting->menuAction());
        menuSetting->addAction(actionFeature);

        retranslateUi(Video_playClass);

        QMetaObject::connectSlotsByName(Video_playClass);
    } // setupUi

    void retranslateUi(QMainWindow *Video_playClass)
    {
        Video_playClass->setWindowTitle(QApplication::translate("Video_playClass", "Video_play", 0));
        actionFeature->setText(QApplication::translate("Video_playClass", "Feature", 0));
        loadVideo->setText(QApplication::translate("Video_playClass", "Load Video", 0));
        playVideo->setText(QApplication::translate("Video_playClass", "Play", 0));
        label->setText(QString());
        menuSetting->setTitle(QApplication::translate("Video_playClass", "Setting", 0));
    } // retranslateUi

};

namespace Ui {
    class Video_playClass: public Ui_Video_playClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_PLAY_H
