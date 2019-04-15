#include "MediaPlayer.h"

void MediaPlayer::PushButtonLoad() {
	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "../../Data/dataset/Ads", tr("RGB File(*.rgb)\n"));
	rgb = QByteArray();
	FileLoader fileLoader(filePath, rgb, 0, 1);

	// Load File
	fileLoader.start();

	// Update UI
	while (fileLoader.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Wait Thread
	fileLoader.wait();

	// Output Image
	LabelImagePrint(rgb.mid(0, 480 * 270 * 3));

	// Update Gloable Variables
	totalFrame = fileLoader.GetTotalFrames();
	framePlayedIndex = 0;
	play = false;
}

void MediaPlayer::PushButtonPlay() {
	// Set Status
	play = true;

	// Load frames in bufffer for display
	FileLoader fileLoader(filePath, rgb, framePlayedIndex, 150);
	fileLoader.start();
	while (fileLoader.isRunning())
		QCoreApplication::processEvents();
	fileLoader.wait();

	// Display the following frames while loading the following frames
	while (framePlayedIndex < totalFrame && play) {
		// Save current rgbBuffer for display in the for loop 
		QByteArray tempRgb = rgb;

		// Load following frames using another thread
		fileLoader.SetStartFrameIndex(framePlayedIndex + 150);
		fileLoader.start();

		// display frames saved in the buffer
		int frameBufferSize = tempRgb.size() / (480 * 270 * 3);
		for (int i = 0; i < frameBufferSize; i++) {
			if (play) {
				LabelImagePrint(tempRgb, i);
				framePlayedIndex++;
				ui.textBrowser_output->append(QString::number(framePlayedIndex));
			}
			else {
				ui.textBrowser_output->append("!" + QString::number(framePlayedIndex));
				return;
			}
			QCoreApplication::processEvents();
		}

		// wait thread
		fileLoader.wait();
	}
}

void MediaPlayer::PushButtonStop() {
	// Set Status
	play = false;
}

void MediaPlayer::LabelImagePrint(QByteArray & frameData) {
	// Initialization
	QImage image = QImage(480, 270, QImage::Format_RGB32);

	// Load Pixels
	for (int i = 0; i < image.height(); i++) {
		for (int j = 0; j < image.width(); j++) {
			int height = image.height();
			int width = image.width();
			int r = frameData[0 * width * height + i * width + j];
			int g = frameData[1 * width * height + i * width + j];
			int b = frameData[2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}

/*
Introduction: 
	this function is used to display a frame stored in the given imageData with a frame offset
Input:
	@ QByteArray & imageData: the given frame
	@ int frameOffset: 
Output
Example: 
*/
void MediaPlayer::LabelImagePrint(QByteArray & frameData, int frameOffset) {
	// Initalization
	QImage image = QImage(480, 270, QImage::Format_RGB32);

	// Load Pixel
	for (int i = 0; i < image.height(); i++) {
		for (int j = 0; j < image.width(); j++) {
			int height = image.height();
			int width = image.width();
			int r = frameData[frameOffset * 3 * width * height + 0 * width * height + i * width + j];
			int g = frameData[frameOffset * 3 * width * height + 1 * width * height + i * width + j];
			int b = frameData[frameOffset * 3 * width * height + 2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}