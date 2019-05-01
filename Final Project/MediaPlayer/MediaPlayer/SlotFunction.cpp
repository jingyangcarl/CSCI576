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
	QString filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "../../Data/dataset/Ads", tr("RGB File(*.rgb)\n WAV File(*.wav)\n"));
	QFileInfo fileInfo(filePath);

	if (fileInfo.suffix() == "rgb") {

		// Save path
		rgbFilePath = filePath;

		// Load file
		VideoLoader videoLoader(rgbFilePath, rgb, 0, 1);
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
		// Save path
		wavFilePath = filePath;

		// Load file
		AudioLoader audioLoader(wavFilePath, wav);
		audioLoader.start();
		// update UI
		while (audioLoader.isRunning())
			QCoreApplication::processEvents();
		// Wait thread
		audioLoader.wait();

		// Update global variables
		wavLoadStatus = audioLoader.GetLoadStatus();
		format = audioLoader.GetAudioFormat();
		totalSample = audioLoader.GetTotalSamples();
	}

	// Update variable status on user interface;
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

	// Load video frames in bufffer for display
	VideoLoader videoLoader(rgbFilePath, rgb, framePlayedIndex, 30);
	videoLoader.start();
	while (videoLoader.isRunning())
		videoLoader.wait();

	// Audio choices
	if (!framePlayedIndex) {
		// Load audio samples in buffer for the first click
		buffer = new QBuffer(&wav);
		buffer->open(QIODevice::ReadOnly);
		audio = new QAudioOutput(QAudioDeviceInfo::defaultInputDevice(), format);
		audio->start(buffer);
		QCoreApplication::processEvents();
	}
	else {
		// Continue playing audio samples
		audio->resume();
		QCoreApplication::processEvents();
	}

	// Display the following frames while loading the following frames
	while (framePlayedIndex < totalFrame && play) {
		// Save current rgbBuffer for display in the for loop
		QByteArray tempRgb = rgb;

		// Load following frames using another thread
		videoLoader.SetStartFrameIndex(framePlayedIndex + 30);
		videoLoader.start();

		// Display frames saved in the buffer
		int frameBufferSize = tempRgb.size() / (width * height * 3);

		// Set up a timer
		QElapsedTimer timer;

		for (int i = 0; i < frameBufferSize; i++) {
			// Start timer
			timer.start();
			if (play) {
				// Print rgb values
				LabelImagePrint(tempRgb, i);
				// Update variables
				framePlayedIndex++;
				samplePlayedIndex = wavLoadStatus ? framePlayedIndex * 1600 : 0;
			}

			// Update variable status on user interface;
			UpdateVariableStatus();
			QCoreApplication::processEvents();

			// Sleep
			int sleepTime = 1000.0 / givenFrameRate - timer.elapsed();
			sleepTime += (rand() % 1) + (rand() % 2) * (rand() % 2) * 1;
			if (sleepTime > 0) Sleep(sleepTime);

			// update framerate
			frameRate = 1000.0 / timer.elapsed();
			sampleRate = wavLoadStatus ? frameRate * 1600 : 0;
		}

		// Wait thread
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
	// Stop video status
	play = false;

	// Stop audio status
	audio->suspend();
}

/*
Introduction: 
	This function is a slot function used to reset status of the player
Input;
Output;
*/
void MediaPlayer::PushButtonReplay() {
	// reset status
	framePlayedIndex = 0;
	play = false;
	audio->stop();

	// hit play button again
	emit PushButtonPlay();
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
	ui.label_frame_width_value->setText(QString::number(width));
	ui.label_frame_height_value->setText(QString::number(height));
	ui.label_frame_status_value->setText(QString::number(framePlayedIndex) + " : " + QString::number(totalFrame));
	ui.label_frame_rate_value->setText(QString::number(frameRate));
	ui.label_sample_status_value->setText(QString::number(samplePlayedIndex) + " : " + QString::number(totalSample));
	ui.label_sample_rate_value->setText(QString::number(sampleRate));
}