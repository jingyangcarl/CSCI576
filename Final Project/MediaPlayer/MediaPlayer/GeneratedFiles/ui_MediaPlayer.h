/********************************************************************************
** Form generated from reading UI file 'MediaPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPLAYER_H
#define UI_MEDIAPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MediaPlayerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_display;
    QLabel *label_image;
    QGridLayout *gridLayout_control;
    QPushButton *pushButton_load;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MediaPlayerClass)
    {
        if (MediaPlayerClass->objectName().isEmpty())
            MediaPlayerClass->setObjectName(QString::fromUtf8("MediaPlayerClass"));
        MediaPlayerClass->resize(1117, 677);
        centralWidget = new QWidget(MediaPlayerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_display = new QGridLayout();
        gridLayout_display->setSpacing(6);
        gridLayout_display->setObjectName(QString::fromUtf8("gridLayout_display"));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));

        gridLayout_display->addWidget(label_image, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_display, 0, 0, 1, 1);

        gridLayout_control = new QGridLayout();
        gridLayout_control->setSpacing(6);
        gridLayout_control->setObjectName(QString::fromUtf8("gridLayout_control"));
        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_control->addWidget(pushButton_load, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_control, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 4);
        gridLayout->setColumnStretch(1, 1);
        MediaPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MediaPlayerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1117, 26));
        MediaPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MediaPlayerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MediaPlayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MediaPlayerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MediaPlayerClass->setStatusBar(statusBar);

        retranslateUi(MediaPlayerClass);

        QMetaObject::connectSlotsByName(MediaPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MediaPlayerClass)
    {
        MediaPlayerClass->setWindowTitle(QApplication::translate("MediaPlayerClass", "MediaPlayer", nullptr));
        label_image->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        pushButton_load->setText(QApplication::translate("MediaPlayerClass", "Load File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerClass: public Ui_MediaPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H
