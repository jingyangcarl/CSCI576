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
#include <QtWidgets/QTextBrowser>
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
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QLabel *label_control;
    QPushButton *pushButton_load;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser_output;
    QLabel *label_wav_status;
    QLabel *label_frame_status;
    QLabel *label_frame_rate;
    QLabel *label_rgb_status_value;
    QLabel *label_frame_width_value;
    QLabel *label_frame_rate_value;
    QLabel *label_rgb_status;
    QLabel *label_wav_status_value;
    QLabel *label_frame_status_value;
    QLabel *label_frame_width;
    QLabel *label_status;
    QLabel *label_frame_height;
    QLabel *label_frame_height_value;
    QLabel *label_9;
    QLabel *label_10;
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
        label_image->setAlignment(Qt::AlignCenter);

        gridLayout_display->addWidget(label_image, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_display, 0, 0, 1, 1);

        gridLayout_control = new QGridLayout();
        gridLayout_control->setSpacing(6);
        gridLayout_control->setObjectName(QString::fromUtf8("gridLayout_control"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));

        gridLayout_2->addWidget(pushButton_play, 2, 0, 1, 1);

        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout_2->addWidget(pushButton_stop, 2, 1, 1, 1);

        label_control = new QLabel(centralWidget);
        label_control->setObjectName(QString::fromUtf8("label_control"));
        label_control->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_control, 0, 0, 1, 2);

        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_2->addWidget(pushButton_load, 1, 0, 1, 2);


        gridLayout_control->addLayout(gridLayout_2, 0, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textBrowser_output = new QTextBrowser(centralWidget);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));

        gridLayout_3->addWidget(textBrowser_output, 8, 0, 1, 2);

        label_wav_status = new QLabel(centralWidget);
        label_wav_status->setObjectName(QString::fromUtf8("label_wav_status"));

        gridLayout_3->addWidget(label_wav_status, 2, 0, 1, 1);

        label_frame_status = new QLabel(centralWidget);
        label_frame_status->setObjectName(QString::fromUtf8("label_frame_status"));

        gridLayout_3->addWidget(label_frame_status, 5, 0, 1, 1);

        label_frame_rate = new QLabel(centralWidget);
        label_frame_rate->setObjectName(QString::fromUtf8("label_frame_rate"));

        gridLayout_3->addWidget(label_frame_rate, 6, 0, 1, 1);

        label_rgb_status_value = new QLabel(centralWidget);
        label_rgb_status_value->setObjectName(QString::fromUtf8("label_rgb_status_value"));

        gridLayout_3->addWidget(label_rgb_status_value, 1, 1, 1, 1);

        label_frame_width_value = new QLabel(centralWidget);
        label_frame_width_value->setObjectName(QString::fromUtf8("label_frame_width_value"));

        gridLayout_3->addWidget(label_frame_width_value, 3, 1, 1, 1);

        label_frame_rate_value = new QLabel(centralWidget);
        label_frame_rate_value->setObjectName(QString::fromUtf8("label_frame_rate_value"));

        gridLayout_3->addWidget(label_frame_rate_value, 6, 1, 1, 1);

        label_rgb_status = new QLabel(centralWidget);
        label_rgb_status->setObjectName(QString::fromUtf8("label_rgb_status"));

        gridLayout_3->addWidget(label_rgb_status, 1, 0, 1, 1);

        label_wav_status_value = new QLabel(centralWidget);
        label_wav_status_value->setObjectName(QString::fromUtf8("label_wav_status_value"));

        gridLayout_3->addWidget(label_wav_status_value, 2, 1, 1, 1);

        label_frame_status_value = new QLabel(centralWidget);
        label_frame_status_value->setObjectName(QString::fromUtf8("label_frame_status_value"));

        gridLayout_3->addWidget(label_frame_status_value, 5, 1, 1, 1);

        label_frame_width = new QLabel(centralWidget);
        label_frame_width->setObjectName(QString::fromUtf8("label_frame_width"));

        gridLayout_3->addWidget(label_frame_width, 3, 0, 1, 1);

        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_status, 0, 0, 1, 2);

        label_frame_height = new QLabel(centralWidget);
        label_frame_height->setObjectName(QString::fromUtf8("label_frame_height"));

        gridLayout_3->addWidget(label_frame_height, 4, 0, 1, 1);

        label_frame_height_value = new QLabel(centralWidget);
        label_frame_height_value->setObjectName(QString::fromUtf8("label_frame_height_value"));

        gridLayout_3->addWidget(label_frame_height_value, 4, 1, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 7, 0, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 7, 1, 1, 1);


        gridLayout_control->addLayout(gridLayout_3, 2, 0, 1, 2);


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
        pushButton_play->setText(QApplication::translate("MediaPlayerClass", "Play", nullptr));
        pushButton_stop->setText(QApplication::translate("MediaPlayerClass", "Stop", nullptr));
        label_control->setText(QApplication::translate("MediaPlayerClass", "Control", nullptr));
        pushButton_load->setText(QApplication::translate("MediaPlayerClass", "Load File", nullptr));
        label_wav_status->setText(QApplication::translate("MediaPlayerClass", "WAV Status", nullptr));
        label_frame_status->setText(QApplication::translate("MediaPlayerClass", "Frame Status", nullptr));
        label_frame_rate->setText(QApplication::translate("MediaPlayerClass", "Frame Rate", nullptr));
        label_rgb_status_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_frame_width_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_frame_rate_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_rgb_status->setText(QApplication::translate("MediaPlayerClass", "RGB Status", nullptr));
        label_wav_status_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_frame_status_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_frame_width->setText(QApplication::translate("MediaPlayerClass", "Frame Width", nullptr));
        label_status->setText(QApplication::translate("MediaPlayerClass", "Status", nullptr));
        label_frame_height->setText(QApplication::translate("MediaPlayerClass", "Frame Height", nullptr));
        label_frame_height_value->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
        label_9->setText(QApplication::translate("MediaPlayerClass", "Sample Rate", nullptr));
        label_10->setText(QApplication::translate("MediaPlayerClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MediaPlayerClass: public Ui_MediaPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPLAYER_H
