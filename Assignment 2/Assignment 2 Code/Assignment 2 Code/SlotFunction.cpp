#include "Assignment2Code.h"

void Assignment2Code::PushButtonLoad() {
	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select Image"), "./Resources", tr("RGB File(*.rgb)\n BMP File(*.bmp)"));
	irgb = QByteArray();
	bool loadStatus = false;
	FileLoader fileLoader(filePath, irgb, loadStatus);

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
	TextBrowserOutputPrint("Loading Finished.\n");

	// Output Image
	LabelImagePrint(irgb);
}

void Assignment2Code::PushButtonJPEGEncoder() {
	// Initialization
	JPEGEncoder encoder(irgb);

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
	TextBrowserOutputPrint("Encoding Finished.\n");

	// get Y matrix, Cr matrix, as well as Cb matrix for display
	dctY = encoder.GetYDCT();
	dctCr = encoder.GetCrDCT();
	dctCb = encoder.GetCbDCT();

	// get YCrCb series
	ycrcb = encoder.YCrCbZigZagSerielization();

	LabelImagePrint(dctY);
}

void Assignment2Code::PushButtonJPEGDecoder() {
	// Initialization
	JPEGDecoder decoder_1(ycrcb);
	JPEGDecoder decoder_2(ycrcb);
	JPEGDecoder decoder_3(ycrcb);
	decoder_1.SetGear(262114);
	decoder_2.SetGear(131072);
	decoder_3.SetGear(16384);

	// Decode
	decoder_1.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 262114.");
	decoder_2.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 131072.");
	decoder_3.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 16384.");

	// Update UI
	TextBrowserOutputPrint("Decoding...");
	while (decoder_1.isRunning() || decoder_2.isRunning() || decoder_3.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	decoder_1.wait();
	TextBrowserOutputPrint("Decoding Thread for 262114 is Finished.");
	decoder_2.wait();
	TextBrowserOutputPrint("Decoding Thread for 131072 is Finished.");
	decoder_3.wait();
	TextBrowserOutputPrint("Decoding Thread for 16384 is Finished.");

	// get rgb series
	orgb_1 = decoder_1.RGBSerielization();
	orgb_2 = decoder_2.RGBSerielization();
	orgb_3 = decoder_3.RGBSerielization();

	LabelImagePrint(orgb_3);
}

void Assignment2Code::PushButtonTest() {
	Testor testor;
	testor.start();
	TextBrowserOutputPrint("Start Test");
	while (testor.isRunning())
		QCoreApplication::processEvents();
	testor.wait();
	TextBrowserOutputPrint("Test Finished.\n");
}

void Assignment2Code::PushButtonShowDCTY() {
	LabelImagePrint(dctY);
}

void Assignment2Code::PushButtonShowDCTCr() {
	LabelImagePrint(dctCr);
}

void Assignment2Code::PushButtonShowDCTCb() {
	LabelImagePrint(dctCb);
}

void Assignment2Code::PushButtonShowOriginalImage() {
	LabelImagePrint(irgb);
}

void Assignment2Code::TextBrowserOutputPrint(QString output) {
	ui.textBrowser_output->append(output);
}

void Assignment2Code::LabelImagePrint(QByteArray & imageData) {
	// Initialization
	QImage image;
	if (imageData.size() / 3 == 512*512)
		image = QImage(512, 512, QImage::Format_RGB32);
	else if (imageData.size() / 3 == 256*256)
		image = QImage(256, 256, QImage::Format_RGB32);
	int height = image.height();
	int width = image.width();

	// Load Pixels
	int r(0), g(0), b(0);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int r = imageData[0 * width * height + i * width + j];
			int g = imageData[1 * width * height + i * width + j];
			int b = imageData[2 * width * height + i * width + j];
			image.setPixel(j, i, qRgb(r, g, b));
		}
	}

	// Print Image
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}