/********************************************************************************
** Form generated from reading UI file 'Assignment1Code.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT1CODE_H
#define UI_ASSIGNMENT1CODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment1CodeClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_load;
    QPushButton *pushButton_play;
    QLabel *label_status;
    QGridLayout *gridLayout_2;
    QLabel *label_frame_index;
    QLabel *label_color_depth_val;
    QLabel *label_frame_size;
    QLabel *label_height;
    QLabel *label_width;
    QLabel *label_width_val;
    QLabel *label_height_val;
    QLabel *label_r_channel_size;
    QLabel *label_b_channel_size_val;
    QLabel *label_g_channel_size_val;
    QLabel *label_frame_size_val;
    QLabel *label_frame_index_val;
    QLabel *label_b_channel_size;
    QLabel *label_color_depth;
    QLabel *label_g_channel_size;
    QLabel *label_r_channel_size_val;
    QLabel *label_frames;
    QLabel *label_frames_val;
    QVBoxLayout *verticalLayout_2_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_1;
    QLabel *label_image;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment1CodeClass)
    {
        if (Assignment1CodeClass->objectName().isEmpty())
            Assignment1CodeClass->setObjectName(QString::fromUtf8("Assignment1CodeClass"));
        Assignment1CodeClass->resize(1293, 819);
        centralWidget = new QWidget(Assignment1CodeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_load = new QPushButton(centralWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_3->addWidget(pushButton_load, 0, 0, 1, 1);

        pushButton_play = new QPushButton(centralWidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));

        gridLayout_3->addWidget(pushButton_play, 1, 0, 1, 1);

        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_status, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_frame_index = new QLabel(centralWidget);
        label_frame_index->setObjectName(QString::fromUtf8("label_frame_index"));

        gridLayout_2->addWidget(label_frame_index, 5, 0, 1, 1);

        label_color_depth_val = new QLabel(centralWidget);
        label_color_depth_val->setObjectName(QString::fromUtf8("label_color_depth_val"));

        gridLayout_2->addWidget(label_color_depth_val, 2, 1, 1, 1);

        label_frame_size = new QLabel(centralWidget);
        label_frame_size->setObjectName(QString::fromUtf8("label_frame_size"));

        gridLayout_2->addWidget(label_frame_size, 7, 0, 1, 1);

        label_height = new QLabel(centralWidget);
        label_height->setObjectName(QString::fromUtf8("label_height"));

        gridLayout_2->addWidget(label_height, 1, 0, 1, 1);

        label_width = new QLabel(centralWidget);
        label_width->setObjectName(QString::fromUtf8("label_width"));

        gridLayout_2->addWidget(label_width, 0, 0, 1, 1);

        label_width_val = new QLabel(centralWidget);
        label_width_val->setObjectName(QString::fromUtf8("label_width_val"));

        gridLayout_2->addWidget(label_width_val, 0, 1, 1, 1);

        label_height_val = new QLabel(centralWidget);
        label_height_val->setObjectName(QString::fromUtf8("label_height_val"));

        gridLayout_2->addWidget(label_height_val, 1, 1, 1, 1);

        label_r_channel_size = new QLabel(centralWidget);
        label_r_channel_size->setObjectName(QString::fromUtf8("label_r_channel_size"));

        gridLayout_2->addWidget(label_r_channel_size, 8, 0, 1, 1);

        label_b_channel_size_val = new QLabel(centralWidget);
        label_b_channel_size_val->setObjectName(QString::fromUtf8("label_b_channel_size_val"));

        gridLayout_2->addWidget(label_b_channel_size_val, 10, 1, 1, 1);

        label_g_channel_size_val = new QLabel(centralWidget);
        label_g_channel_size_val->setObjectName(QString::fromUtf8("label_g_channel_size_val"));

        gridLayout_2->addWidget(label_g_channel_size_val, 9, 1, 1, 1);

        label_frame_size_val = new QLabel(centralWidget);
        label_frame_size_val->setObjectName(QString::fromUtf8("label_frame_size_val"));

        gridLayout_2->addWidget(label_frame_size_val, 7, 1, 1, 1);

        label_frame_index_val = new QLabel(centralWidget);
        label_frame_index_val->setObjectName(QString::fromUtf8("label_frame_index_val"));

        gridLayout_2->addWidget(label_frame_index_val, 5, 1, 1, 1);

        label_b_channel_size = new QLabel(centralWidget);
        label_b_channel_size->setObjectName(QString::fromUtf8("label_b_channel_size"));

        gridLayout_2->addWidget(label_b_channel_size, 10, 0, 1, 1);

        label_color_depth = new QLabel(centralWidget);
        label_color_depth->setObjectName(QString::fromUtf8("label_color_depth"));

        gridLayout_2->addWidget(label_color_depth, 2, 0, 1, 1);

        label_g_channel_size = new QLabel(centralWidget);
        label_g_channel_size->setObjectName(QString::fromUtf8("label_g_channel_size"));

        gridLayout_2->addWidget(label_g_channel_size, 9, 0, 1, 1);

        label_r_channel_size_val = new QLabel(centralWidget);
        label_r_channel_size_val->setObjectName(QString::fromUtf8("label_r_channel_size_val"));

        gridLayout_2->addWidget(label_r_channel_size_val, 8, 1, 1, 1);

        label_frames = new QLabel(centralWidget);
        label_frames->setObjectName(QString::fromUtf8("label_frames"));

        gridLayout_2->addWidget(label_frames, 3, 0, 1, 1);

        label_frames_val = new QLabel(centralWidget);
        label_frames_val->setObjectName(QString::fromUtf8("label_frames_val"));

        gridLayout_2->addWidget(label_frames_val, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalLayout_2_2 = new QVBoxLayout();
        verticalLayout_2_2->setSpacing(6);
        verticalLayout_2_2->setObjectName(QString::fromUtf8("verticalLayout_2_2"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2_2->addWidget(textEdit);


        verticalLayout_2->addLayout(verticalLayout_2_2);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName(QString::fromUtf8("verticalLayout_1"));
        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setAlignment(Qt::AlignCenter);

        verticalLayout_1->addWidget(label_image);


        gridLayout->addLayout(verticalLayout_1, 0, 0, 1, 1);

        Assignment1CodeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment1CodeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1293, 26));
        Assignment1CodeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment1CodeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment1CodeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment1CodeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment1CodeClass->setStatusBar(statusBar);

        retranslateUi(Assignment1CodeClass);

        QMetaObject::connectSlotsByName(Assignment1CodeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment1CodeClass)
    {
        Assignment1CodeClass->setWindowTitle(QApplication::translate("Assignment1CodeClass", "Assignment1Code", nullptr));
        pushButton_load->setText(QApplication::translate("Assignment1CodeClass", "Open a File", nullptr));
        pushButton_play->setText(QApplication::translate("Assignment1CodeClass", "Play", nullptr));
        label_status->setText(QApplication::translate("Assignment1CodeClass", "File Status", nullptr));
        label_frame_index->setText(QApplication::translate("Assignment1CodeClass", "Frame Index", nullptr));
        label_color_depth_val->setText(QApplication::translate("Assignment1CodeClass", "Color_Depth_Val", nullptr));
        label_frame_size->setText(QApplication::translate("Assignment1CodeClass", "Frame Size", nullptr));
        label_height->setText(QApplication::translate("Assignment1CodeClass", "Height", nullptr));
        label_width->setText(QApplication::translate("Assignment1CodeClass", "Width", nullptr));
        label_width_val->setText(QApplication::translate("Assignment1CodeClass", "Width_Val", nullptr));
        label_height_val->setText(QApplication::translate("Assignment1CodeClass", "Heigh_Val", nullptr));
        label_r_channel_size->setText(QApplication::translate("Assignment1CodeClass", "R Channel Size", nullptr));
        label_b_channel_size_val->setText(QApplication::translate("Assignment1CodeClass", "B_Channel_Size_Val", nullptr));
        label_g_channel_size_val->setText(QApplication::translate("Assignment1CodeClass", "G_Channel_Size_Val", nullptr));
        label_frame_size_val->setText(QApplication::translate("Assignment1CodeClass", "Frame_Size_Val", nullptr));
        label_frame_index_val->setText(QApplication::translate("Assignment1CodeClass", "Frame_Index_Val", nullptr));
        label_b_channel_size->setText(QApplication::translate("Assignment1CodeClass", "B Channel Size", nullptr));
        label_color_depth->setText(QApplication::translate("Assignment1CodeClass", "Color Depth", nullptr));
        label_g_channel_size->setText(QApplication::translate("Assignment1CodeClass", "G Channel Size", nullptr));
        label_r_channel_size_val->setText(QApplication::translate("Assignment1CodeClass", "R_Channel_Size_Val", nullptr));
        label_frames->setText(QApplication::translate("Assignment1CodeClass", "Frames", nullptr));
        label_frames_val->setText(QApplication::translate("Assignment1CodeClass", "Frames_Val", nullptr));
        label_image->setText(QApplication::translate("Assignment1CodeClass", "IImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment1CodeClass: public Ui_Assignment1CodeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT1CODE_H
