#pragma once

#include <QtWidgets/QMainWindow>
#include <qfile.h>
#include <qfiledialog.h>
#include <qelapsedtimer.h>
#include <Windows.h>
#include "FileLoader.h"
#include "SeamCarvingOperator.h"
#include "AntiAliasingOperator.h"
#include "ui_Assignment1Code.h"

class Assignment1Code : public QMainWindow {
	Q_OBJECT

public:
	Assignment1Code(QWidget *parent = Q_NULLPTR);

	/*-------------Initialization.cpp------------*/
	void layoutInitialization();
	void widgetInitialization();
	void connectionInitialization();

	/*-------------SLOTFunction .cpp------------*/
public slots:
	void loadFile();
	void play();
	void setWidthScalerVal(int val);
	void setHeightScalerVal(int val);
	void setFPSScalerVal(int val);
	void setAntiAliasingVal(int val);
	void setLetterBoxingVal(int val);
	void setSeamCarvingVal(int val);

private:
	Ui::Assignment1CodeClass ui;

	// private variable
	QString filePath;
	//QVector<QVector<char>> RGB;
	QByteArray RGB;
	QVector<int> fileDetail;
	bool loadStatus;

	// image detail
	int width;
	int height;
	int colorDepth;
	int frameIndex;
	int frameSize;
	int frames;
	int rChannelSize;
	int gChannelSize;
	int bChannelSize;
};
