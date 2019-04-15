#pragma once
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>

class FileLoader : public QThread {
public:
	FileLoader(QString &filePath, QByteArray &rgb);
	FileLoader(QString &filePath, QByteArray &rgb, int startFrameIndex, int frameCount);
	void SetStartFrameIndex(int startFrameIndex);
	int GetTotalFrames();

protected:
	void run();

private:
	// Variable References
	QString &filePath;
	QByteArray &rgb;
	int startFrameIndex;
	int frameCount;
	int frameSize = 3 * 480 * 270;
	int totalFrames = -1;

	// Function
	void load();
};