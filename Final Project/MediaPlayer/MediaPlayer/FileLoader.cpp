#include "FileLoader.h"

FileLoader::FileLoader(QString &filePath, QByteArray & rgb) :
	filePath(filePath), rgb(rgb) {
	startFrameIndex = 0;
	frameCount = 150;
	return;
}

FileLoader::FileLoader(QString & filePath, QByteArray & rgb, qint64 startFrameIndex, qint64 frameCount) :
	filePath(filePath), rgb(rgb), startFrameIndex(startFrameIndex), frameCount(frameCount) {
	return;
}

void FileLoader::SetStartFrameIndex(int startFrameIndex) {
	this->startFrameIndex = startFrameIndex;
}

int FileLoader::GetTotalFrames() {
	return totalFrames;
}

void FileLoader::run() {
	load();
	return;
}

void FileLoader::load() {

	QFile file(filePath);
	QFileInfo fileInfo(file);

	if (!file.exists()) return;
	else if (!file.open(QIODevice::ReadOnly)) return;
	else {
		// the file is exist and opened successfully

		// count total frames
		totalFrames = file.size() / frameSize;

		// read file
		if (fileInfo.suffix() == "rgb") {
			// move the pointer to startFrameIndex
			file.seek(startFrameIndex * frameSize);
			// read the following frameCount frames
			rgb = file.read(frameCount * frameSize);
		}
		else if (fileInfo.suffix() == "bmp") {
		}
	}

	return;
}