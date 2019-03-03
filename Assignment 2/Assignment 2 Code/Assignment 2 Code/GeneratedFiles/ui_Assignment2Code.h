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
    QPushButton *pushButton_dcty;
    QPushButton *pushButton_dctcr;
    QPushButton *pushButton_test;
    QTextBrowser *textBrowser_output;
    QPushButton *pushButton_jpeg_encoder;
    QLabel *label_2;
    QPushButton *pushButton_load;
    QPushButton *pushButton_dctcb;
    QLabel *label_3;
    QPushButton *pushButton_original_image;
    QPushButton *pushButton_jpeg_decoder;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
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
        pushButton_dcty = new QPushButton(centralWidget);
        pushButton_dcty->setObjectName(QString::fromUtf8("pushButton_dcty"));

        gridLayout_control->addWidget(pushButton_dcty, 4, 0, 1, 1);

        pushButton_dctcr = new QPushButton(centralWidget);
        pushButton_dctcr->setObjectName(QString::fromUtf8("pushButton_dctcr"));

        gridLayout_control->addWidget(pushButton_dctcr, 4, 1, 1, 1);

        pushButton_test = new QPushButton(centralWidget);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));

        gridLayout_control->addWidget(pushButton_test, 8, 0, 1, 3);

        textBrowser_output = new QTextBrowser(centralWidget);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));

        gridLayout_control->addWidget(textBrowser_output, 9, 0, 1, 3);

        pushButton_jpeg_encoder = new QPushButton(centralWidget);
        pushButton_jpeg_encoder->setObjectName(QString::fromUtf8("pushButton_jpeg_encoder"));

        gridLayout_control->addWidget(pushButton_jpeg_encoder, 3, 0, 1, 3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_control->addWidget(label_2, 2, 0, 1, 3);

        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_control->addWidget(pushButton_load, 0, 0, 1, 3);

        pushButton_dctcb = new QPushButton(centralWidget);
        pushButton_dctcb->setObjectName(QString::fromUtf8("pushButton_dctcb"));

        gridLayout_control->addWidget(pushButton_dctcb, 4, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_control->addWidget(label_3, 5, 0, 1, 3);

        pushButton_original_image = new QPushButton(centralWidget);
        pushButton_original_image->setObjectName(QString::fromUtf8("pushButton_original_image"));

        gridLayout_control->addWidget(pushButton_original_image, 1, 0, 1, 3);

        pushButton_jpeg_decoder = new QPushButton(centralWidget);
        pushButton_jpeg_decoder->setObjectName(QString::fromUtf8("pushButton_jpeg_decoder"));

        gridLayout_control->addWidget(pushButton_jpeg_decoder, 6, 0, 1, 3);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_control->addWidget(pushButton, 7, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_control->addWidget(pushButton_2, 7, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_control->addWidget(pushButton_3, 7, 2, 1, 1);


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
        pushButton_dcty->setText(QApplication::translate("Assignment2CodeClass", "DCTY", nullptr));
        pushButton_dctcr->setText(QApplication::translate("Assignment2CodeClass", "DCTCr", nullptr));
        pushButton_test->setText(QApplication::translate("Assignment2CodeClass", "Test", nullptr));
        pushButton_jpeg_encoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG Encoder", nullptr));
        label_2->setText(QApplication::translate("Assignment2CodeClass", "Encoder", nullptr));
        pushButton_load->setText(QApplication::translate("Assignment2CodeClass", "Load Image", nullptr));
        pushButton_dctcb->setText(QApplication::translate("Assignment2CodeClass", "DCTCb", nullptr));
        label_3->setText(QApplication::translate("Assignment2CodeClass", "Decoder", nullptr));
        pushButton_original_image->setText(QApplication::translate("Assignment2CodeClass", "Original Image", nullptr));
        pushButton_jpeg_decoder->setText(QApplication::translate("Assignment2CodeClass", "JPEG Decoder", nullptr));
        pushButton->setText(QApplication::translate("Assignment2CodeClass", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Assignment2CodeClass", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("Assignment2CodeClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment2CodeClass: public Ui_Assignment2CodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT2CODE_H
