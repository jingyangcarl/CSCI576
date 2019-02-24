#include "Assignment2Code.h"

void Assignment2Code::PushButtonLoad() {

	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select Image"), "./Resources", tr("RGB File(*.rgb)\n BMP File(*.bmp)"));
	rgb = QByteArray();
	loadStatus = false;
	FileLoader fileLoader(filePath, rgb, loadStatus);

	// Load File
	fileLoader.start();
	TextBrowserOutputPrint("Start Loading File.");

	// Update UI
	TextBrowserOutputPrint("Loading...");
	while (fileLoader.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	fileLoader.wait();
	TextBrowserOutputPrint("Loading Finished.");

	// Output Image
	LabelImagePrint(rgb);
}

void Assignment2Code::TextBrowserOutputPrint(QString output) {
	ui.textBrowser_output->append(output + '\n');
}

void Assignment2Code::LabelImagePrint(QByteArray & rgb) {
	// Initialization
	QImage image(512, 512, QImage::Format_RGB32);
	int height = image.height();
	int width = image.width();

	// Load Pixels
	int r(0), g(0), b(0);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int r = rgb[i*width * 3 + 3 * j];
			int g = rgb[i*width * 3 + 3 * j + 1];
			int b = rgb[i*width * 3 + 3 * j + 2];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}
