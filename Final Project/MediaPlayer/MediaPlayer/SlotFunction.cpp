#include "MediaPlayer.h"

void MediaPlayer::PushButtonLoad() {
	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "../../Data/dataset/Ads", tr("RGB File(*.rgb)\n"));
	irgb = QByteArray();
	FileLoader fileLoader(filePath, irgb);

	// Load File
	fileLoader.start();

	// Update UI
	while (fileLoader.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Wait Thread
	fileLoader.wait();

	// Output Image
	LabelImagePrint(irgb.mid(0, 480 * 270 * 3));

	// Update Gloable Variables
	totalFrame = irgb.size() / (480 * 270 * 3);
	currentFrame = 0;
	play = false;
}

void MediaPlayer::PushButtonPlay() {
	// Set Status
	play = true;

	// Display
	for (currentFrame; currentFrame < totalFrame; currentFrame++) {
		if (play) {
			LabelImagePrint(irgb, currentFrame);
			ui.textBrowser_output->append(QString::number(currentFrame));
		}
		else {
			ui.textBrowser_output->append("!" + QString::number(currentFrame));
			return;
		}
		QCoreApplication::processEvents();
	}
}

void MediaPlayer::PushButtonStop() {
	// Set Status
	play = false;
}

void MediaPlayer::LabelImagePrint(QByteArray & imageData) {
	// Initialization
	QImage image = QImage(480, 270, QImage::Format_RGB32);

	// Load Pixels
	for (int i = 0; i < image.height(); i++) {
		for (int j = 0; j < image.width(); j++) {
			int height = image.height();
			int width = image.width();
			int r = imageData[0 * width * height + i * width + j];
			int g = imageData[1 * width * height + i * width + j];
			int b = imageData[2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}

void MediaPlayer::LabelImagePrint(QByteArray & imageData, int frameIndex) {
	// Initalization
	QImage image = QImage(480, 270, QImage::Format_RGB32);

	// Load Pixel
	for (int i = 0; i < image.height(); i++) {
		for (int j = 0; j < image.width(); j++) {
			int height = image.height();
			int width = image.width();
			int r = imageData[frameIndex * 3 * width * height + 0 * width * height + i * width + j];
			int g = imageData[frameIndex * 3 * width * height + 1 * width * height + i * width + j];
			int b = imageData[frameIndex * 3 * width * height + 2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}