#pragma once
#include <qaudiobuffer.h>
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>
#include "WavFile.h"

class AudioLoader : public QThread {
public:
	AudioLoader(QString filePath, QByteArray &wav);
	QAudioFormat GetAudioFormat();
	bool GetLoadStatus();

protected:
	void run();

private:
	// variable reference
	QByteArray &wav;

	// variables
	QString filePath;
	QAudioFormat format;
	bool loadStatus;

	// Function
	void load();
};