#pragma once

#include <QtWidgets/QMainWindow>
#include <qfile.h>
#include <qfiledialog.h>
#include "FileLoader.h"
#include "ui_Assignment1Code.h"

class Assignment1Code : public QMainWindow {
	Q_OBJECT

public:
	Assignment1Code(QWidget *parent = Q_NULLPTR);

	/*-------------Initialization.cpp------------*/
	void layoutInitialization();
	void widgetInitialization();
	void connectionInitialization();

	void frameReader();
	void frameSeparator();

	// SLOT function
public slots:
	void loadFile();
	void play();

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
