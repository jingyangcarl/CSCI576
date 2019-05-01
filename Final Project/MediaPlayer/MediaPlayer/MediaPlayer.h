#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayer.h"
#include <qfiledialog.h>
#include <qaudiooutput.h>
#include <qbuffer.h>
#include <qelapsedtimer.h>
#include <qbuffer.h>
#include "VideoLoader.h"
#include "AudioLoader.h"
#include "qt_windows.h"

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
	void PushButtonReplay();
	void LabelImagePrint(QByteArray & frameData);
	void LabelImagePrint(QByteArray & frameData, int frameIndex);
	void UpdateVariableStatus();

private:
	Ui::MediaPlayerClass ui;

	// Private Variables
	QString rgbFilePath;
	QByteArray rgb = QByteArray();
	bool rgbLoadStatus = 0;
	QString wavFilePath;
	QByteArray wav = QByteArray();
	bool wavLoadStatus = 0;

	bool play = true;
	int totalFrame = 0;
	int framePlayedIndex = 0;
	double frameRate = 0;
	QAudioFormat format;
	QBuffer *buffer;
	QAudioOutput *audio;
};
