/********************************************************************************
** Form generated from reading UI file 'Assignment2Code.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT2CODE_H
#define UI_ASSIGNMENT2CODE_H

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

class Ui_Assignment2CodeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_display;
    QLabel *label_image;
    QGridLayout *gridLayout_control;
    QTextBrowser *textBrowser_output;
    QPushButton *pushButton_dctcb;
    QPushButton *pushButton_jpeg_131072;
    QPushButton *pushButton_jp2_65535;
    QPushButton *pushButton_jp2_4096;
    QLabel *label_3;
    QPushButton *pushButton_jpeg_8192;
    QPushButton *pushButton_dctcr;
    QPushButton *pushButton_dctb;
    QPushButton *pushButton_jpeg_16384;
    QPushButton *pushButton_dctg;
    QPushButton *pushButton_dcty;
    QPushButton *pushButton_dwtr;
    QPushButton *pushButton_original_image;
    QPushButton *pushButton_jp2_8192;
    QPushButton *pushButton_jp2_262144;
    QPushButton *pushButton_load;
    QPushButton *pushButton_jpeg_4096;
    QPushButton *pushButton_jpeg_encoder;
    QPushButton *pushButton_jpeg_decoder;
    QPushButton *pushButton_jpeg_262144;
    QPushButton *pushButton_jp2_decoder;
    QPushButton *pushButton_jp2_131072;
    QLabel *label_2;
    QPushButton *pushButton_dctr;
    QPushButton *pushButton_jp2_encoder;
    QPushButton *pushButton_jp2_16384;
    QPushButton *pushButton_jpeg_65535;
    QPushButton *pushButton_dwtg;
    QPushButton *pushButton_dwtb;
    QPushButton *pushButton_test;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment2CodeClass)
    {
        if (Assignment2CodeClass->objectName().isEmpty())
            Assignment2CodeClass->setObjectName(QString::fromUtf8("Assignment2CodeClass"));
        Assignment2CodeClass->resize(1191, 735);
        centralWidget = new QWidget(Assignment2CodeClass);
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
        textBrowser_output = new QTextBrowser(centralWidget);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));

        gridLayout_control->addWidget(textBrowser_output, 17, 0, 1, 3);

        pushButton_dctcb = new QPushButton(centralWidget);
        pushButton_dctcb->setObjectName(QString::fromUtf8("pushButton_dctcb"));

        gridLayout_control->addWidget(pushButton_dctcb, 5, 2, 1, 1);

        pushButton_jpeg_131072 = new QPushButton(centralWidget);
        pushButton_jpeg_131072->setObjectName(QString::fromUtf8("pushButton_jpeg_131072"));

        gridLayout_control->addWidget(pushButton_jpeg_131072, 11, 1, 1, 1);

        pushButton_jp2_65535 = new QPushButton(centralWidget);
        pushButton_jp2_65535->setObjectName(QString::fromUtf8("pushButton_jp2_65535"));

        gridLayout_control->addWidget(pushButton_jp2_65535, 14, 2, 1, 1);

        pushButton_jp2_4096 = new QPushButton(centralWidget);
        pushButton_jp2_4096->setObjectName(QString::fromUtf8("pushButton_jp2_4096"));

        gridLayout_control->addWidget(pushButton_jp2_4096, 15, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_control->addWidget(label_3, 9, 0, 1, 3);

        pushButton_jpeg_8192 = new QPushButton(centralWidget);
        pushButton_jpeg_8192->setObjectName(QString::fromUtf8("pushButton_jpeg_8192"));

        gridLayout_control->addWidget(pushButton_jpeg_8192, 12, 1, 1, 1);

        pushButton_dctcr = new QPushButton(centralWidget);
        pushButton_dctcr->setObjectName(QString::fromUtf8("pushButton_dctcr"));

        gridLayout_control->addWidget(pushButton_dctcr, 5, 1, 1, 1);

        pushButton_dctb = new QPushButton(centralWidget);
        pushButton_dctb->setObjectName(QString::fromUtf8("pushButton_dctb"));

        gridLayout_control->addWidget(pushButton_dctb, 4, 2, 1, 1);

        pushButton_jpeg_16384 = new QPushButton(centralWidget);
        pushButton_jpeg_16384->setObjectName(QString::fromUtf8("pushButton_jpeg_16384"));

        gridLayout_control->addWidget(pushButton_jpeg_16384, 12, 0, 1, 1);

        pushButton_dctg = new QPushButton(centralWidget);
        pushButton_dctg->setObjectName(QString::fromUtf8("pushButton_dctg"));

        gridLayout_control->addWidget(pushButton_dctg, 4, 1, 1, 1);

        pushButton_dcty = new QPushButton(centralWidget);
        pushButton_dcty->setObjectName(QString::fromUtf8("pushButton_dcty"));

        gridLayout_control->addWidget(pushButton_dcty, 5, 0, 1, 1);

        pushButton_dwtr = new QPushButton(centralWidget);
        pushButton_dwtr->setObjectName(QString::fromUtf8("pushButton_dwtr"));

        gridLayout_control->addWidget(pushButton_dwtr, 7, 0, 1, 1);

        pushButton_original_image = new QPushButton(centralWidget);
        pushButton_original_image->setObjectName(QString::fromUtf8("pushButton_original_image"));

        gridLayout_control->addWidget(pushButton_original_image, 1, 0, 1, 3);

        pushButton_jp2_8192 = new QPushButton(centralWidget);
        pushButton_jp2_8192->setObjectName(QString::fromUtf8("pushButton_jp2_8192"));

        gridLayout_control->addWidget(pushButton_jp2_8192, 15, 1, 1, 1);

        pushButton_jp2_262144 = new QPushButton(centralWidget);
        pushButton_jp2_262144->setObjectName(QString::fromUtf8("pushButton_jp2_262144"));

        gridLayout_control->addWidget(pushButton_jp2_262144, 14, 0, 1, 1);

        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_control->addWidget(pushButton_load, 0, 0, 1, 3);

        pushButton_jpeg_4096 = new QPushButton(centralWidget);
        pushButton_jpeg_4096->setObjectName(QString::fromUtf8("pushButton_jpeg_4096"));

        gridLayout_control->addWidget(pushButton_jpeg_4096, 12, 2, 1, 1);

        pushButton_jpeg_encoder = new QPushButton(centralWidget);
        pushButton_jpeg_encoder->setObjectName(QString::fromUtf8("pushButton_jpeg_encoder"));

        gridLayout_control->addWidget(pushButton_jpeg_encoder, 3, 0, 1, 3);

        pushButton_jpeg_decoder = new QPushButton(centralWidget);
        pushButton_jpeg_decoder->setObjectName(QString::fromUtf8("pushButton_jpeg_decoder"));

        gridLayout_control->addWidget(pushButton_jpeg_decoder, 10, 0, 1, 3);

        pushButton_jpeg_262144 = new QPushButton(centralWidget);
        pushButton_jpeg_262144->setObjectName(QString::fromUtf8("pushButton_jpeg_262144"));

        gridLayout_control->addWidget(pushButton_jpeg_262144, 11, 0, 1, 1);

        pushButton_jp2_decoder = new QPushButton(centralWidget);
        pushButton_jp2_decoder->setObjectName(QString::fromUtf8("pushButton_jp2_decoder"));

        gridLayout_control->addWidget(pushButton_jp2_decoder, 13, 0, 1, 3);

        pushButton_jp2_131072 = new QPushButton(centralWidget);
        pushButton_jp2_131072->setObjectName(QString::fromUtf8("pushButton_jp2_131072"));

        gridLayout_control->addWidget(pushButton_jp2_131072, 14, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_control->addWidget(label_2, 2, 0, 1, 3);

        pushButton_dctr = new QPushButton(centralWidget);
        pushButton_dctr->setObjectName(QString::fromUtf8("pushButton_dctr"));

        gridLayout_control->addWidget(pushButton_dctr, 4, 0, 1, 1);

        pushButton_jp2_encoder = new QPushButton(centralWidget);
        pushButton_jp2_encoder->setObjectName(QString::fromUtf8("pushButton_jp2_encoder"));

        gridLayout_control->addWidget(pushButton_jp2_encoder, 6, 0, 1, 3);

        pushButton_jp2_16384 = new QPushButton(centralWidget);
        pushButton_jp2_16384->setObjectName(QString::fromUtf8("pushButton_jp2_16384"));

        gridLayout_control->addWidget(pushButton_jp2_16384, 15, 0, 1, 1);

        pushButton_jpeg_65535 = new QPushButton(centralWidget);
        pushButton_jpeg_65535->setObjectName(QString::fromUtf8("pushButton_jpeg_65535"));

        gridLayout_control->addWidget(pushButton_jpeg_65535, 11, 2, 1, 1);

        pushButton_dwtg = new QPushButton(centralWidget);
        pushButton_dwtg->setObjectName(QString::fromUtf8("pushButton_dwtg"));

        gridLayout_control->addWidget(pushButton_dwtg, 7, 1, 1, 1);

        pushButton_dwtb = new QPushButton(centralWidget);
        pushButton_dwtb->setObjectName(QString::fromUtf8("pushButton_dwtb"));

        gridLayout_control->addWidget(pushButton_dwtb, 7, 2, 1, 1);

        pushButton_test = new QPushButton(centralWidget);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));

        gridLayout_control->addWidget(pushButton_test, 18, 0, 1, 3);


        gridLayout->addLayout(gridLayout_control, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 4);
        gridLayout->setColumnStretch(1, 1);
        Assignment2CodeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment2CodeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1191, 26));
        Assignment2CodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment2CodeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment2CodeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment2CodeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment2CodeClass->setStatusBar(statusBar);

        retranslateUi(Assignment2CodeClass);

        QMetaObject::connectSlotsByName(Assignment2CodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment2CodeClass)
    {
        Assignment2CodeClass->setWindowTitle(QApplication::translate("Assignment2CodeClass", "Assignment2Code", nullptr));
        label_image->setText(QApplication::translate("Assignment2CodeClass", "label_image", nullptr));
        pushButton_dctcb->setText(QApplication::translate("Assignment2CodeClass", "DCTCb", nullptr));
        pushButton_jpeg_131072->setText(QApplication::translate("Assignment2CodeClass", "131072", nullptr));
        pushButton_jp2_65535->setText(QApplication::translate("Assignment2CodeClass", "65535", nullptr));
        pushButton_jp2_4096->setText(QApplication::translate("Assignment2CodeClass", "4096", nullptr));
        label_3->setText(QApplication::translate("Assignment2CodeClass", "Decoder", nullptr));
        pushButton_jpeg_8192->setText(QApplication::translate("Assignment2CodeClass", "8192", nullptr));
        pushButton_dctcr->setText(QApplication::translate("Assignment2CodeClass", "DCTCr", nullptr));
        pushButton_dctb->setText(QApplication::translate("Assignment2CodeClass", "DCTB", nullptr));
        pushButton_jpeg_16384->setText(QApplication::translate("Assignment2CodeClass", "16384", nullptr));
        pushButton_dctg->setText(QApplication::translate("Assignment2CodeClass", "DCTG", nullptr));
        pushButton_dcty->setText(QApplication::translate("Assignment2CodeClass", "DCTY", nullptr));
        pushButton_dwtr->setText(QApplication::translate("Assignment2CodeClass", "DWTR", nullptr));
        pushButton_original_image->setText(QApplication::translate("Assignment2CodeClass", "Original Image", nullptr));
        pushButton_jp2_8192->setText(QApplication::translate("Assignment2CodeClass", "8192", nullptr));
        pushButton_jp2_262144->setText(QApplication::translate("Assignment2CodeClass", "262144", nullptr));
        pushButton_load->setText(QApplication::translate("Assignment2CodeClass", "Load Image", nullptr));
        pushButton_jpeg_4096->setText(QApplication::translate("Assignment2CodeClass", "4096", nullptr));
        pushButton_jpeg_encoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG Encoder", nullptr));
        pushButton_jpeg_decoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG Decoder", nullptr));
        pushButton_jpeg_262144->setText(QApplication::translate("Assignment2CodeClass", "262144", nullptr));
        pushButton_jp2_decoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG 2000 Decoder", nullptr));
        pushButton_jp2_131072->setText(QApplication::translate("Assignment2CodeClass", "131072", nullptr));
        label_2->setText(QApplication::translate("Assignment2CodeClass", "Encoder", nullptr));
        pushButton_dctr->setText(QApplication::translate("Assignment2CodeClass", "DCTR", nullptr));
        pushButton_jp2_encoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG 2000 Encoder", nullptr));
        pushButton_jp2_16384->setText(QApplication::translate("Assignment2CodeClass", "16384", nullptr));
        pushButton_jpeg_65535->setText(QApplication::translate("Assignment2CodeClass", "65535", nullptr));
        pushButton_dwtg->setText(QApplication::translate("Assignment2CodeClass", "DWTG", nullptr));
        pushButton_dwtb->setText(QApplication::translate("Assignment2CodeClass", "DWTB", nullptr));
        pushButton_test->setText(QApplication::translate("Assignment2CodeClass", "Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment2CodeClass: public Ui_Assignment2CodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT2CODE_H
