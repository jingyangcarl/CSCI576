#include "FileLoader.h"

FileLoader::FileLoader(QString &filePath, QByteArray & rgb) :
	filePath(filePath), rgb(rgb) {
	return;
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
		if (fileInfo.suffix() == "rgb") {
			int frameSize = 3 * 480 * 270;
			int frameCount = 150;
			rgb = file.read(frameSize * frameCount);
		}
		else if (fileInfo.suffix() == "bmp") {
			rgb = file.readAll();
			rgb = rgb.mid(0);
		}
	}

	return;
}