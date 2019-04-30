#pragma once
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>

class VideoLoader : public QThread {
public:
	VideoLoader(QString filePath, QByteArray &rgb);
	VideoLoader(QString filePath, QByteArray &rgb, qint64 startFrameIndex, qint64 frameCount);
	void SetStartFrameIndex(int startFrameIndex);
	int GetTotalFrames();

protected:
	void run();

private:
	// variable reference
	QByteArray &rgb;

	// variables
	QString filePath;
	qint64 startFrameIndex;
	qint64 frameCount;
	qint64 frameSize = 3 * 480 * 270;
	qint64 totalFrames = -1;

	// Function
	void load();
};
