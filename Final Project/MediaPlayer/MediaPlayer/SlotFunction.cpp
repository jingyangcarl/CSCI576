#include "MediaPlayer.h"

void MediaPlayer::PushButtonLoad() {
	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "../../Data/dataset/Videos", tr("RGB File(*.rgb)\n"));
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