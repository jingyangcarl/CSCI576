#pragma once
#include <qaudiobuffer.h>
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>
#include "WavFile.h"

class FileLoader : public QThread {
public:
	FileLoader(QString &filePath, QByteArray &rgb, QByteArray &wav);
	FileLoader(QString &filePath, QByteArray &rgb, QByteArray &wav, qint64 startFrameIndex, qint64 frameCount);
	void SetStartFrameIndex(int startFrameIndex);
	int GetTotalFrames();

protected:
	void run();

private:
	// Variable References
	QString &filePath;
	QByteArray &rgb;
	QByteArray &wav;
	qint64 startFrameIndex;
	qint64 frameCount;
	qint64 frameSize = 3 * 480 * 270;
	qint64 totalFrames = -1;

	// Function
	void load();
};