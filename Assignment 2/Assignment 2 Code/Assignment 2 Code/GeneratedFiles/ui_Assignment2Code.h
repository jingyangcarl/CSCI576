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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment2CodeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment2CodeClass)
    {
        if (Assignment2CodeClass->objectName().isEmpty())
            Assignment2CodeClass->setObjectName(QString::fromUtf8("Assignment2CodeClass"));
        Assignment2CodeClass->resize(600, 400);
        menuBar = new QMenuBar(Assignment2CodeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Assignment2CodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment2CodeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment2CodeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Assignment2CodeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Assignment2CodeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Assignment2CodeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment2CodeClass->setStatusBar(statusBar);

        retranslateUi(Assignment2CodeClass);

        QMetaObject::connectSlotsByName(Assignment2CodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment2CodeClass)
    {
        Assignment2CodeClass->setWindowTitle(QApplication::translate("Assignment2CodeClass", "Assignment2Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment2CodeClass: public Ui_Assignment2CodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT2CODE_H
