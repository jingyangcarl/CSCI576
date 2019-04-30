#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayer.h"
#include <qfiledialog.h>
//#include "FileLoader.h"
#include "VideoLoader.h"

class MediaPlayer : public QMainWindow
{
	Q_OBJECT

public:
	MediaPlayer(QWidget *parent = Q_NULLPTR);

	/*-----------------Initialization.cpp---------------------*/
	void ConnectionInitialization();
	/*-----------------SlotFunction.cpp---------------------*/
public slots:
	void PushButtonLoad();
	void PushButtonPlay();
	void PushButtonStop();
	void LabelImagePrint(QByteArray & frameData);
	void LabelImagePrint(QByteArray & frameData, int frameIndex);

private:
	Ui::MediaPlayerClass ui;

	// Private Variables
	QString filePath;
	QByteArray rgb;
	QByteArray wav;

	bool play = true;
	int totalFrame = 0;
	int framePlayedIndex = 0;
};
