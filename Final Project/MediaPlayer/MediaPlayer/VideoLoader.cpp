#include "VideoLoader.h"

VideoLoader::VideoLoader(QString filePath, QByteArray & rgb) : 
	filePath(filePath), rgb(rgb) {
	startFrameIndex = 0;
	frameCount = 30;
}

VideoLoader::VideoLoader(QString filePath, QByteArray & rgb, qint64 startFrameIndex, qint64 frameCount) :
	filePath(filePath), rgb(rgb), startFrameIndex(startFrameIndex), frameCount(frameCount) {
	return;
}

void VideoLoader::SetStartFrameIndex(int startFrameIndex) {
	this->startFrameIndex = startFrameIndex;
}

qint64 VideoLoader::GetTotalFrames() {
	return totalFrames;
}

bool VideoLoader::GetLoadStatus() {
	return loadStatus;
}

void VideoLoader::run() {
	load();
	return;
}

void VideoLoader::load() {

	QFile file(filePath);
	QFileInfo fileInfo(file);

	if (!file.exists()) return;

	if (fileInfo.suffix() == "rgb") {

		if (!file.open(QIODevice::ReadOnly)) return;

		// move the pointer to startFrameIndex;
		file.seek(startFrameIndex * frameSize);
		// read the following frameCount frames
		rgb = file.read(frameCount * frameSize);
		// count total frames
		totalFrames = file.size() / frameSize;
		// change load status;
		loadStatus = true;
	}
	else {

	}
}
