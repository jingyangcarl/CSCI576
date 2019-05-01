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

class MediaPlayer : public QMainWindow {
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
	QString wavFilePath;
	QByteArray wav = QByteArray();

	// Status variables
	bool play = true;
	bool rgbLoadStatus = 0;
	bool wavLoadStatus = 0;
	int width = 480;
	int height = 270;
	int framePlayedIndex = 0;
	int totalFrame = 0;
	double frameRate = 0;
	int samplePlayedIndex = 0;
	int totalSample = 0;
	double sampleRate = 0;

	QAudioFormat format;
	QBuffer *buffer;
	QAudioOutput *audio;
	int givenFrameRate = 31;
};
