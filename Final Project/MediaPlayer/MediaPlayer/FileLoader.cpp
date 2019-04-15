#include "FileLoader.h"

FileLoader::FileLoader(QString &filePath, QByteArray & rgb, QByteArray &wav) :
	filePath(filePath), rgb(rgb), wav(wav) {
	startFrameIndex = 0;
	frameCount = 150;
	return;
}

FileLoader::FileLoader(QString & filePath, QByteArray & rgb, QByteArray &wav, qint64 startFrameIndex, qint64 frameCount) :
	filePath(filePath), rgb(rgb), wav(wav), startFrameIndex(startFrameIndex), frameCount(frameCount) {
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
	else {
		// the file is exist
		if (fileInfo.suffix() == "rgb") {
			if (!file.open(QIODevice::ReadOnly)) return;
			else {
				// the file is opened successfully
				// move the pointer to startFrameIndex
				file.seek(startFrameIndex * frameSize);
				// read the following frameCount frames
				rgb = file.read(frameCount * frameSize);
				// count total frames
				totalFrames = file.size() / frameSize;
			}
		}
		else if (fileInfo.suffix() == "wav") {
			WavFile wavFile;
			wavFile.setFileName(filePath);

		}
	}

	//if (!file.exists()) return;
	//else if (!file.open(QIODevice::ReadOnly)) return;
	//else {
	//	// the file is exist and opened successfully

	//	if (fileInfo.suffix() == "rgb") {
	//		// move the pointer to startFrameIndex
	//		file.seek(startFrameIndex * frameSize);
	//		// read the following frameCount frames
	//		rgb = file.read(frameCount * frameSize);
	//		// count total frames
	//		totalFrames = file.size() / frameSize;
	//	}
	//	else if (fileInfo.suffix() == "wav") {
	//		WavFile wavFile;
	//		wavFile.setFileName(filePath);
	//		wav = file.readAll();
	//	}
	//}

	//return;
}