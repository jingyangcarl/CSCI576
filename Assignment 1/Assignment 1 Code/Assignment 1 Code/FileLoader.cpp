#include "FileLoader.h"

//FileLoader::FileLoader(QString filePath, QVector<QVector<char>>& RGB, QVector<int> &fileDetail, bool & loadStatus) :
//	RGB(RGB), fileDetail(fileDetail), loadStatus(loadStatus) {
//	this->filePath = filePath;
//}

FileLoader::FileLoader(QString filePath, QByteArray & RGB, QVector<int>& fileDetail, bool & loadStatus)
	: RGB(RGB), fileDetail(fileDetail), loadStatus(loadStatus) {
	this->filePath = filePath;
}

void FileLoader::setFilePath(QString filePath) {
	this->filePath = filePath;
}

QString FileLoader::getFilePath() {
	return this->filePath;
}

void FileLoader::run() {
	load();
}

int FileLoader::load() {
	// JPEG is a compressed data format, there is no pixels in the .jpg file
	// BMP is an uncompressed data format, pixels can be found in the file

	QFile file(filePath);
	QFileInfo fileInfor(file);

	if (!file.exists()) loadStatus = false;
	else if (!file.open(QIODevice::ReadOnly)) loadStatus = false;

	// initialization
	//char currentByte;
	//int byteCounter(0);
	//RGB = QVector<QVector<char>>(3, QVector<char>());

	if (fileInfor.suffix() == "bmp") {
		// read head to fileDetail

		QVector<unsigned char> byteBuffer;
		RGB = file.readAll();

		for (int i = 0; i < 54; i++) {
			// read head to Detail
			switch (i) {
			case 18:
			case 19:
			case 20: byteBuffer.append(RGB[i]); break;
			case 21: byteBuffer.append(RGB[i]);
				// width
				fileDetail.append(byteBuffer[0] * pow(256, 0) + byteBuffer[1] * pow(256, 1) + byteBuffer[2] * pow(256, 2) + byteBuffer[3] * pow(256, 3));
				byteBuffer.clear();
				break;
			case 22:
			case 23:
			case 24: byteBuffer.append(RGB[i]); break;
			case 25: byteBuffer.append(RGB[i]);
				// height
				fileDetail.append(byteBuffer[0] * pow(256, 0) + byteBuffer[1] * pow(256, 1) + byteBuffer[2] * pow(256, 2) + byteBuffer[3] * pow(256, 3));
				byteBuffer.clear();
				break;
			case 28: byteBuffer.append(RGB[i]); break;
			case 29: byteBuffer.append(RGB[i]);
				// color depth or bits per pixel
				fileDetail.append(byteBuffer[0] * pow(256, 0) + byteBuffer[1] * pow(256, 1));
				byteBuffer.clear();
				break;
			case 34:
			case 35:
			case 36: byteBuffer.append(RGB[i]); break;
			case 37: byteBuffer.append(RGB[i]);
				// frame index
				fileDetail.append(0);
				// frame size or image size
				fileDetail.append(byteBuffer[0] * pow(256, 0) + byteBuffer[1] * pow(256, 1) + byteBuffer[2] * pow(256, 2) + byteBuffer[3] * pow(256, 3));
				// frames
				fileDetail.append(1);
				byteBuffer.clear();
				break;
			}
		}

		// read RGB
		RGB = RGB.mid(54, RGB.size() - 54);
		// remove break bytes between each line
		for (int i = 0; i < fileDetail[1]; i++) {
			RGB.remove((i + 1)*fileDetail[0] * 3, 2);
		}
	}
	else if (fileInfor.suffix() == "rgb") {
		// For 'video_prison_960_540.rgb', there are 155520000 bytes in the file
		// where each frame takes up 960*540*3 = 1555200 bytes
		// hence, there are 155520000/1555200 = 100 frames without head in each image.
		// read each bitmap one by one

		// for the first 10 frames, there is nothing

		// read RGB
		RGB = file.readAll();

		// width
		//int width = 960;
		int width = 1280;
		fileDetail.push_back(width);
		// height
		//int height = 540;
		int height = 1024;
		fileDetail.push_back(height);
		// color depth
		fileDetail.push_back(24);
		// frames
		fileDetail.push_back(RGB.size() / (3 * width * height));
		// frame index
		fileDetail.push_back(0);
		// frame size
		fileDetail.push_back(width * height * 3);
		// R channel size
		fileDetail.push_back(width * height);
		// G channel size
		fileDetail.push_back(width * height);
		// B channel size
		fileDetail.push_back(width * height);
	}

	loadStatus = true;
	return 0;
}