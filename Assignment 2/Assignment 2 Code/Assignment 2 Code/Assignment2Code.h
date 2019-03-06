#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <qbytearray.h>
#include "ui_Assignment2Code.h"
#include "FileLoader.h"
#include "JPEGEncoder.h"
#include "JPEGDecoder.h"
#include "JP2Encoder.h"
#include "JP2Decoder.h"
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
	void PushButtonJP2Encoder();
	void PushButtonJP2Decoder();
	void PushButtonTest();
	void PushButtonShowDCTY();
	void PushButtonShowDCTCr();
	void PushButtonShowDCTCb();
	void PushButtonShowDCTR();
	void PushButtonShowDCTG();
	void PushButtonShowDCTB();
	void PushButtonShowDWTR();
	void PushButtonShowDWTG();
	void PushButtonShowDWTB();
	void PushButtonShowOriginalImage();
	void PushButtonShowJPEG_262114();
	void PushButtonShowJPEG_131072();
	void PushButtonShowJPEG_65535();
	void PushButtonShowJPEG_16384();
	void PushButtonShowJPEG_8192();
	void PushButtonShowJPEG_4096();
	void PushButtonShowJP2_262114();
	void PushButtonShowJP2_131072();
	void PushButtonShowJP2_65535();
	void PushButtonShowJP2_16384();
	void PushButtonShowJP2_8192();
	void PushButtonShowJP2_4096();
	void PushButtonJPEGProgressiveAnalysis();
	void PushButtonJPEGPAPlay();
	void PushButtonJP2ProgressiveAnalysis();
	void PushButtonJP2PAPlay();
	void TextBrowserOutputPrint(QString output);
	void LabelImagePrint(QByteArray & rgb);

private:
	Ui::Assignment2CodeClass ui;

	// private variable
	QString filePath;
	QByteArray irgb;
	QByteArray orgb_jpeg_1;
	QByteArray orgb_jpeg_2;
	QByteArray orgb_jpeg_3;
	QByteArray orgb_jpeg_4;
	QByteArray orgb_jpeg_5;
	QByteArray orgb_jpeg_6;
	QVector<QByteArray> orgb_jpeg_pa;
	QByteArray orgb_jp2_1;
	QByteArray orgb_jp2_2;
	QByteArray orgb_jp2_3;
	QByteArray orgb_jp2_4;
	QByteArray orgb_jp2_5;
	QByteArray orgb_jp2_6;
	QVector<QByteArray> orgb_jp2_pa;
	QVector<float> orgb;
	QVector<float> oycbcr;
	QByteArray dctR;
	QByteArray dctG;
	QByteArray dctB;
	QByteArray dctY;
	QByteArray dctCb;
	QByteArray dctCr;
	QByteArray dwtR;
	QByteArray dwtG;
	QByteArray dwtB;
};
