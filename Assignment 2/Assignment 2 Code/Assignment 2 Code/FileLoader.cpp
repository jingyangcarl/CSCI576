#include "FileLoader.h"

FileLoader::FileLoader(QString &filePath, QByteArray & rgb, bool &loadStatus) :
	filePath(filePath), rgb(rgb), loadStatus(loadStatus) {
	return;
}

void FileLoader::run() {
	load();
	return;
}

void FileLoader::load() {

	QFile file(filePath);
	QFileInfo fileInfo(file);

	if (!file.exists()) loadStatus = false;
	else if (!file.open(QIODevice::ReadOnly)) loadStatus = false;
	else {
		// the file is exist and opened successfully

		if (fileInfo.suffix() == "rgb") {
			rgb = file.readAll();
		}
		else if (fileInfo.suffix() == "bmp") {

		}
		loadStatus = true;
	}

	return;
}