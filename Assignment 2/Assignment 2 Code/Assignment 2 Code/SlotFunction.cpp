#include "Assignment2Code.h"

void Assignment2Code::PushButtonLoadFile() {

	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select Image"), "./", tr("RGB File(*.rgb)\n BMP File(*.bmp)"));
	rgb = QByteArray();
	loadStatus = false;
	FileLoader fileLoader(filePath, rgb, loadStatus);

	// Load File
	fileLoader.start();
	TextBrowserPrint("Start Loading File.");

	// Update UI
	TextBrowserPrint("Loading...");
	while (fileLoader.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	fileLoader.wait();
	TextBrowserPrint("Loading Finished.");

}

void Assignment2Code::TextBrowserPrint(QString output) {
	ui.textBrowser_output->append(output + '\n');
}