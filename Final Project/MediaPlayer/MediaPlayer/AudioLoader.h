#pragma once
#include <qaudiobuffer.h>
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>
#include "WavFile.h"

class AudioLoader : public QThread {
public:
	AudioLoader(QString filePath, QByteArray &wav);
	AudioLoader(QString filePath, QByteArray &wav, qint64 startSampleIndex);
	void SetStartSampleIndex(qint64 startSampleIndex);
	QAudioFormat GetAudioFormat();
	qint64 GetTotalSamples();
	bool GetLoadStatus();

protected:
	void run();

private:
	// variable reference
	QByteArray &wav;

	// variables
	QString filePath;
	qint64 startSampleIndex;
	QAudioFormat format;
	bool loadStatus;
	qint64 totalSamples;

	// Function
	void load();
};