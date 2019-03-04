#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <qbytearray.h>
#include "ui_Assignment2Code.h"
#include "FileLoader.h"
#include "JPEGEncoder.h"
#include "JPEGDecoder.h"
#include "Testor.h"

class Assignment2Code : public QMainWindow {
	Q_OBJECT

public:
	Assignment2Code(QWidget *parent = Q_NULLPTR);

	/*-----------------Initialization.cpp---------------------*/
	void ConnectionInitialization();

	/*-----------------SlogFunction.cpp---------------------*/
public slots:
	void PushButtonLoad();
	void PushButtonJPEGEncoder();
	void PushButtonJPEGDecoder();
	void PushButtonTest();
	void PushButtonShowDCTY();
	void PushButtonShowDCTCr();
	void PushButtonShowDCTCb();
	void PushButtonShowDCTR();
	void PushButtonShowDCTG();
	void PushButtonShowDCTB();
	void PushButtonShowOriginalImage();
	void PushButtonShow262114();
	void PushButtonShow131072();
	void PushButtonShow16384();
	void TextBrowserOutputPrint(QString output);
	void LabelImagePrint(QByteArray & rgb);

private:
	Ui::Assignment2CodeClass ui;

	// private variable
	QString filePath;
	QByteArray irgb;
	QByteArray orgb_1;
	QByteArray orgb_2;
	QByteArray orgb_3;
	QVector<float> orgb;
	QVector<float> oycbcr;
	QByteArray dctR;
	QByteArray dctG;
	QByteArray dctB;
	QByteArray dctY;
	QByteArray dctCb;
	QByteArray dctCr;
};
