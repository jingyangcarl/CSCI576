#include "Assignment2Code.h"

void Assignment2Code::PushButtonLoad() {
	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select Image"), "./Resources", tr("RGB File(*.rgb)\n BMP File(*.bmp)"));
	rgb = QByteArray();
	bool loadStatus = false;
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

void Assignment2Code::PushButtonJPEGEncoder() {
	// Initialization
	bool encodeStatus = false;
	JPEGEncoder encoder(rgb, encodeStatus);

	// Encode
	encoder.start();
	TextBrowserOutputPrint("Start Performing JPEG Encoding.");

	// Update UI
	TextBrowserOutputPrint("Encoding...");
	while (encoder.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	encoder.wait();
	TextBrowserOutputPrint("Encoding Finished.");

	// Output Image
	LabelImagePrint(rgb);
}

void Assignment2Code::PushButtonJPEGDecoder() {
}

void Assignment2Code::PushButtonTest() {
	Testor testor;
	testor.start();
	while (testor.isRunning())
		QCoreApplication::processEvents();
	testor.wait();
}

void Assignment2Code::TextBrowserOutputPrint(QString output) {
	ui.textBrowser_output->append(output);
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
			int r = rgb[0 * width * height + i * width + j];
			int g = rgb[1 * width * height + i * width + j];
			int b = rgb[2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}