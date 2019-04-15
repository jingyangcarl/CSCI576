#include "MediaPlayer.h"

/*
Introduction:
	This function is a slot function used to respond to the click event on the Load Button,
	which will open a file dialog for file selection
Input;
Output;
*/
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

/*
Introduction:
	This function is a slot function used to respond to the click event on the Play Button.
	which will continue playing the given video
Input;
Output;
*/
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

/*
Introduction:
	This function is a slot function used to respond to the click event on the Stop Button, 
	which will stop the playing video
Input;
Output;
*/
void MediaPlayer::PushButtonStop() {
	// Set Status
	play = false;
}

/*
Introduction:
	This function is used to display the first frame in the given frameData
Input:
	@ QByteArray & frameData: the given frame data
Output;
Example:
	Suppose QByteArray frameData stores five frames,
	LabelImagePrint(frameData); will display the 1st frame in the frameData
*/
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
	This function is used to display a frame stored in the given frameData with a frame offset
Input:
	@ QByteArray & frameData: the given frame data
	@ int frameOffset: frame offset in the given frame data
Output;
Example: 
	Suppose QByteArray frameData stores five frames,
	LabelImagePrint(frameData, 3); will display the 3rd frame in the frameData
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