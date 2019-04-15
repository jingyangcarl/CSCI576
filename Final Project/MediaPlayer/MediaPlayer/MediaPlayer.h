#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayer.h"
#include <qfiledialog.h>
#include "FileLoader.h"

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
	void LabelImagePrint(QByteArray & imageData);
	void LabelImagePrint(QByteArray & imageData, int frameIndex);

private:
	Ui::MediaPlayerClass ui;

	// Private Variables
	QString filePath;
	QByteArray irgb;
	QByteArray orgb;

	bool play = true;
	int totalFrame = 0;
	int currentFrame = 0;
};
