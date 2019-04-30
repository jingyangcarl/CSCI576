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
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "../../Data/dataset/Ads", tr("RGB File(*.rgb)\n WAV File(*.wav)\n"));
	QFileInfo fileInfo(filePath);
	rgb = QByteArray();
	wav = QByteArray();

	if (fileInfo.suffix() == "rgb") {
		VideoLoader videoLoader(filePath, rgb, 0, 1);

		// Load File
		videoLoader.start();

		// update UI
		while (videoLoader.isRunning())
			QCoreApplication::processEvents();

		// Wait Thread
		videoLoader.wait();

		// Output Image
		LabelImagePrint(rgb.mid(0, 480 * 270 * 3));

		// Update Gloable Variables
		rgbLoadStatus = videoLoader.GetLoadStatus();
		totalFrame = videoLoader.GetTotalFrames();
		framePlayedIndex = 0;
		play = false;
	}
	else if (fileInfo.suffix() == "wav") {
		AudioLoader audioLoader(filePath, wav);

		// Load File
		audioLoader.start();

		// update UI
		while (audioLoader.isRunning())
			QCoreApplication::processEvents();

		// wait thread
		audioLoader.wait();

		// update global variables
		wavLoadStatus = audioLoader.GetLoadStatus();
		format = audioLoader.GetAudioFormat();
	}
	
	// update variable status on user interface;
	UpdateVariableStatus();
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
	VideoLoader videoLoader(filePath, rgb, framePlayedIndex, 150);
	videoLoader.start();
	while (videoLoader.isRunning())
		QCoreApplication::processEvents();
	videoLoader.wait();

	// try play sound here
	QBuffer buffer(&wav);
	buffer.open(QIODevice::ReadOnly);
	QAudioOutput *audio = new QAudioOutput(QAudioDeviceInfo::defaultInputDevice(), format);
	audio->start(&buffer);

	// Display the following frames while loading the following frames
	while (framePlayedIndex < totalFrame && play) {
		// Save current rgbBuffer for display in the for loop
		QByteArray tempRgb = rgb;

		// Load following frames using another thread
		videoLoader.SetStartFrameIndex(framePlayedIndex + 150);
		videoLoader.start();

		// display frames saved in the buffer
		int frameBufferSize = tempRgb.size() / (480 * 270 * 3);

		// set up a timer
		QElapsedTimer timer;

		for (int i = 0; i < frameBufferSize; i++) {
			if (play) {
				// start timer
				timer.start();

				// print rgb values
				LabelImagePrint(tempRgb, i);

				// sleep
				Sleep(22);

				// update variables
				framePlayedIndex++;
				ui.textBrowser_output->append(QString::number(framePlayedIndex));
				frameRate = 1000.0 / timer.elapsed();
			}
			// update variable status on user interface;
			UpdateVariableStatus();
			QCoreApplication::processEvents();
		}

		// wait thread
		videoLoader.wait();
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

void MediaPlayer::UpdateVariableStatus() {
	ui.label_rgb_status_value->setText(rgbLoadStatus ? "Loaded" : "Unloaded");
	ui.label_wav_status_value->setText(wavLoadStatus ? "Loaded" : "Unloaded");
	ui.label_frame_width_value->setText(QString::number(480));
	ui.label_frame_height_value->setText(QString::number(270));
	ui.label_frame_status_value->setText(QString::number(framePlayedIndex) + " : " + QString::number(totalFrame));
	ui.label_frame_rate_value->setText(QString::number(frameRate));

}