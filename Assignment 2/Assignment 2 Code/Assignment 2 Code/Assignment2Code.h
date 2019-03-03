#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
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
	void PushButtonShowOriginalImage();
	void TextBrowserOutputPrint(QString output);
	void LabelImagePrint(QByteArray & rgb);

private:
	Ui::Assignment2CodeClass ui;

	// private variable
	QString filePath;
	QByteArray irgb;
	QByteArray orgb;
	QByteArray ycrcb;
	QByteArray dctY;
	QByteArray dctCr;
	QByteArray dctCb;
};
