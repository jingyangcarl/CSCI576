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
    QPushButton *pushButton_load;
    QTextBrowser *textBrowser_output;
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

        gridLayout_display->addWidget(label_image, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_display, 0, 0, 1, 1);

        gridLayout_control = new QGridLayout();
        gridLayout_control->setSpacing(6);
        gridLayout_control->setObjectName(QString::fromUtf8("gridLayout_control"));
        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_control->addWidget(pushButton_load, 0, 0, 1, 1);

        textBrowser_output = new QTextBrowser(centralWidget);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));

        gridLayout_control->addWidget(textBrowser_output, 1, 0, 1, 1);


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
        pushButton_load->setText(QApplication::translate("Assignment2CodeClass", "Load Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment2CodeClass: public Ui_Assignment2CodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT2CODE_H
