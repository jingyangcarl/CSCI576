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
	TextBrowserOutputPrint("Loading Finished.");

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
	TextBrowserOutputPrint("Encoding Finished.");

	// get Y matrix, Cr matrix, as well as Cb matrix for display
	dctY = encoder.GetYDCT();
	dctCr = encoder.GetCrDCT();
	dctCb = encoder.GetCbDCT();
	dctR = encoder.GetRDCT();
	dctG = encoder.GetGDCT();
	dctB = encoder.GetBDCT();

	// get YCrCb series
	oycbcr = encoder.YCrCbZigZagSerielization();
	orgb = encoder.RGBZigZagSerielization();

	LabelImagePrint(dctR);
}

void Assignment2Code::PushButtonJPEGDecoder() {
	// Initialization
	JPEGDecoder decoder_1(orgb, 262114);
	JPEGDecoder decoder_2(orgb, 131072);
	JPEGDecoder decoder_3(orgb, 65535);
	JPEGDecoder decoder_4(orgb, 16384);
	JPEGDecoder decoder_5(orgb, 8192);
	JPEGDecoder decoder_6(orgb, 4096);

	// Decode
	decoder_1.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 262114.");
	decoder_2.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 131072.");
	decoder_3.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 65535.");
	decoder_4.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 16384.");
	decoder_5.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 8192.");
	decoder_6.start();
	TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear 4096.");

	// Update UI
	TextBrowserOutputPrint("Decoding...");
	while (
		decoder_1.isRunning() ||
		decoder_2.isRunning() ||
		decoder_3.isRunning() ||
		decoder_4.isRunning() ||
		decoder_5.isRunning() ||
		decoder_6.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	decoder_1.wait();
	TextBrowserOutputPrint("Decoding Thread for 262114 is Finished.");
	decoder_2.wait();
	TextBrowserOutputPrint("Decoding Thread for 131072 is Finished.");
	decoder_3.wait();
	TextBrowserOutputPrint("Decoding Thread for 65535 is Finished.");
	decoder_4.wait();
	TextBrowserOutputPrint("Decoding Thread for 16384 is Finished.");
	decoder_5.wait();
	TextBrowserOutputPrint("Decoding Thread for 8192 is Finished.");
	decoder_6.wait();
	TextBrowserOutputPrint("Decoding Thread for 4096 is Finished.");

	// get rgb series
	orgb_jpeg_1 = decoder_1.RGBSerielization();
	orgb_jpeg_2 = decoder_2.RGBSerielization();
	orgb_jpeg_3 = decoder_3.RGBSerielization();
	orgb_jpeg_4 = decoder_4.RGBSerielization();
	orgb_jpeg_5 = decoder_5.RGBSerielization();
	orgb_jpeg_6 = decoder_6.RGBSerielization();

	LabelImagePrint(orgb_jpeg_1);
}

void Assignment2Code::PushButtonJP2Encoder() {
	// Initialization
	JP2Encoder encoder(irgb);

	// Encode
	encoder.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Encoding.");

	// Update UI
	TextBrowserOutputPrint("Encoding...");
	while (encoder.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	encoder.wait();
	TextBrowserOutputPrint("Encoding Finished.");

	// get R matrix, G matrix, as well as B matrix for display
	dwtR = encoder.GetRDWT();
	dwtG = encoder.GetGDWT();
	dwtB = encoder.GetBDWT();

	// get RGB series
	orgb = encoder.RGBZigZagSerielization();
}

void Assignment2Code::PushButtonJP2Decoder() {
	// Initialization
	JP2Decoder decoder_1(orgb, 262114);
	JP2Decoder decoder_2(orgb, 131072);
	JP2Decoder decoder_3(orgb, 65535);
	JP2Decoder decoder_4(orgb, 16384);
	JP2Decoder decoder_5(orgb, 8192);
	JP2Decoder decoder_6(orgb, 4096);

	// Decode
	decoder_1.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 262114.");
	decoder_2.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 131072.");
	decoder_3.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 65535.");
	decoder_4.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 16384.");
	decoder_5.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 8192.");
	decoder_6.start();
	TextBrowserOutputPrint("Start Performing JPEG 2000 Decoding Thread on Gear 4096.");

	// Update UI
	TextBrowserOutputPrint("Decoding...");
	while (
		decoder_1.isRunning() ||
		decoder_2.isRunning() ||
		decoder_3.isRunning() ||
		decoder_4.isRunning() ||
		decoder_5.isRunning() ||
		decoder_6.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	decoder_1.wait();
	TextBrowserOutputPrint("Decoding Thread for 262114 is Finished.");
	decoder_2.wait();
	TextBrowserOutputPrint("Decoding Thread for 131072 is Finished.");
	decoder_3.wait();
	TextBrowserOutputPrint("Decoding Thread for 65535 is Finished.");
	decoder_4.wait();
	TextBrowserOutputPrint("Decoding Thread for 16384 is Finished.");
	decoder_5.wait();
	TextBrowserOutputPrint("Decoding Thread for 8192 is Finished.");
	decoder_6.wait();
	TextBrowserOutputPrint("Decoding Thread for 4096 is Finished.");

	// get rgb series
	orgb_jp2_1 = decoder_1.RGBSerielization();
	orgb_jp2_2 = decoder_2.RGBSerielization();
	orgb_jp2_3 = decoder_3.RGBSerielization();
	orgb_jp2_4 = decoder_4.RGBSerielization();
	orgb_jp2_5 = decoder_5.RGBSerielization();
	orgb_jp2_6 = decoder_6.RGBSerielization();

	LabelImagePrint(orgb_jp2_1);
}

void Assignment2Code::PushButtonTest() {
	Testor testor;
	testor.start();
	TextBrowserOutputPrint("Start Test");
	while (testor.isRunning())
		QCoreApplication::processEvents();
	testor.wait();
	TextBrowserOutputPrint("Test Finished.");
}

void Assignment2Code::PushButtonShowDCTY() {
	LabelImagePrint(dctY);
	TextBrowserOutputPrint("PushButtonShowDCTY");
}

void Assignment2Code::PushButtonShowDCTCr() {
	LabelImagePrint(dctCr);
	TextBrowserOutputPrint("PushButtonShowDCTCr");
}

void Assignment2Code::PushButtonShowDCTCb() {
	LabelImagePrint(dctCb);
	TextBrowserOutputPrint("PushButtonShowDCTCb");
}

void Assignment2Code::PushButtonShowDCTR() {
	LabelImagePrint(dctR);
	TextBrowserOutputPrint("PushButtonShowDCTR");
}

void Assignment2Code::PushButtonShowDCTG() {
	LabelImagePrint(dctG);
	TextBrowserOutputPrint("PushButtonShowDCTG");
}

void Assignment2Code::PushButtonShowDCTB() {
	LabelImagePrint(dctB);
	TextBrowserOutputPrint("PushButtonShowDCTB");
}

void Assignment2Code::PushButtonShowDWTR() {
	LabelImagePrint(dwtR);
	TextBrowserOutputPrint("PushButtonShowDWTR");
}

void Assignment2Code::PushButtonShowDWTG() {
	LabelImagePrint(dwtG);
	TextBrowserOutputPrint("PushButtonShowDWTG");
}

void Assignment2Code::PushButtonShowDWTB() {
	LabelImagePrint(dwtB);
	TextBrowserOutputPrint("PushButtonShowDWTB");
}

void Assignment2Code::PushButtonShowOriginalImage() {
	LabelImagePrint(irgb);
	TextBrowserOutputPrint("PushButtonShowOriginalImage");
}

void Assignment2Code::PushButtonShowJPEG_262114() {
	LabelImagePrint(orgb_jpeg_1);
	TextBrowserOutputPrint("PushButtonShowJPEG_262114");
}

void Assignment2Code::PushButtonShowJPEG_131072() {
	LabelImagePrint(orgb_jpeg_2);
	TextBrowserOutputPrint("PushButtonShowJPEG_131072");
}

void Assignment2Code::PushButtonShowJPEG_65535() {
	LabelImagePrint(orgb_jpeg_3);
	TextBrowserOutputPrint("PushButtonShowJPEG_65535");
}

void Assignment2Code::PushButtonShowJPEG_16384() {
	LabelImagePrint(orgb_jpeg_4);
	TextBrowserOutputPrint("PushButtonShowJPEG_16384");
}

void Assignment2Code::PushButtonShowJPEG_8192() {
	LabelImagePrint(orgb_jpeg_5);
	TextBrowserOutputPrint("PushButtonShowJPEG_8192");
}

void Assignment2Code::PushButtonShowJPEG_4096() {
	LabelImagePrint(orgb_jpeg_6);
	TextBrowserOutputPrint("PushButtonShowJPEG_4096");
}

void Assignment2Code::PushButtonShowJP2_262114() {
	LabelImagePrint(orgb_jp2_1);
	TextBrowserOutputPrint("PushButtonShowJP2_262114");
}

void Assignment2Code::PushButtonShowJP2_131072() {
	LabelImagePrint(orgb_jp2_2);
	TextBrowserOutputPrint("PushButtonShowJP2_131072");
}

void Assignment2Code::PushButtonShowJP2_65535() {
	LabelImagePrint(orgb_jp2_3);
	TextBrowserOutputPrint("PushButtonShowJP2_65535");
}

void Assignment2Code::PushButtonShowJP2_16384() {
	LabelImagePrint(orgb_jp2_4);
	TextBrowserOutputPrint("PushButtonShowJP2_16384");
}

void Assignment2Code::PushButtonShowJP2_8192() {
	LabelImagePrint(orgb_jp2_5);
	TextBrowserOutputPrint("PushButtonShowJP2_8192");
}

void Assignment2Code::PushButtonShowJP2_4096() {
	LabelImagePrint(orgb_jp2_6);
	TextBrowserOutputPrint("PushButtonShowJP2_4096");
}

void Assignment2Code::PushButtonJPEGProgressiveAnalysis() {
	// Initialization
	JPEGDecoder decoder_1(orgb);
	JPEGDecoder decoder_2(orgb);
	JPEGDecoder decoder_3(orgb);
	JPEGDecoder decoder_4(orgb);

	for (int i = 0; i < 64 / 4; i++) {
		decoder_1.SetGear((4 * i + 1) * 4096);
		decoder_2.SetGear((4 * i + 2) * 4096);
		decoder_3.SetGear((4 * i + 3) * 4096);
		decoder_4.SetGear((4 * i + 4) * 4096);
		// Decode
		decoder_1.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 1) * 4096));
		decoder_2.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 2) * 4096));
		decoder_3.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 3) * 4096));
		decoder_4.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 4) * 4096));
		while (
			decoder_1.isRunning() ||
			decoder_2.isRunning() ||
			decoder_3.isRunning() ||
			decoder_4.isRunning()) {
			QCoreApplication::processEvents();
		}
		// Waite Thread
		decoder_1.wait();
		decoder_2.wait();
		decoder_3.wait();
		decoder_4.wait();
		// get rgb series
		orgb_jpeg_pa.append(decoder_1.RGBSerielization());
		orgb_jpeg_pa.append(decoder_2.RGBSerielization());
		orgb_jpeg_pa.append(decoder_3.RGBSerielization());
		orgb_jpeg_pa.append(decoder_4.RGBSerielization());
	}
}

void Assignment2Code::PushButtonJPEGPAPlay() {
	for (int i = 0; i < orgb_jpeg_pa.size(); i++) {
		LabelImagePrint(orgb_jpeg_pa[i]);
		QCoreApplication::processEvents();
		Sleep(100);
	}
}

void Assignment2Code::PushButtonJP2ProgressiveAnalysis() {
	// Initialization
	JP2Decoder decoder_1(orgb);
	JP2Decoder decoder_2(orgb);
	JP2Decoder decoder_3(orgb);
	JP2Decoder decoder_4(orgb);

	for (int i = 0; i < 64 / 4; i++) {
		decoder_1.SetGear((4 * i + 1) * 4096);
		decoder_2.SetGear((4 * i + 2) * 4096);
		decoder_3.SetGear((4 * i + 3) * 4096);
		decoder_4.SetGear((4 * i + 4) * 4096);
		// Decode
		decoder_1.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 1) * 4096));
		decoder_2.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 2) * 4096));
		decoder_3.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 3) * 4096));
		decoder_4.start();
		TextBrowserOutputPrint("Start Performing JPEG Decoding Thread on Gear " + QString::number((4 * i + 4) * 4096));
		while (
			decoder_1.isRunning() ||
			decoder_2.isRunning() ||
			decoder_3.isRunning() ||
			decoder_4.isRunning()) {
			QCoreApplication::processEvents();
		}
		// Waite Thread
		decoder_1.wait();
		decoder_2.wait();
		decoder_3.wait();
		decoder_4.wait();
		// get rgb series
		orgb_jp2_pa.append(decoder_1.RGBSerielization());
		orgb_jp2_pa.append(decoder_2.RGBSerielization());
		orgb_jp2_pa.append(decoder_3.RGBSerielization());
		orgb_jp2_pa.append(decoder_4.RGBSerielization());
	}
}

void Assignment2Code::PushButtonJP2PAPlay() {
	for (int i = 0; i < orgb_jp2_pa.size(); i++) {
		LabelImagePrint(orgb_jp2_pa[i]);
		QCoreApplication::processEvents();
		Sleep(100);
	}
}

void Assignment2Code::TextBrowserOutputPrint(QString output) {
	ui.textBrowser_output->append(output);
}

void Assignment2Code::LabelImagePrint(QByteArray & imageData) {
	// Initialization
	QImage image;
	if (imageData.size() / 3 == 512 * 512)
		image = QImage(512, 512, QImage::Format_RGB32);
	else if (imageData.size() / 3 == 256 * 256)
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