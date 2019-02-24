#include "Assignment2Code.h"

void Assignment2Code::PushButtonLoadFile() {

	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select Image"), "./", tr("RGB File(*.rgb)\n BMP File(*.bmp)"));
	rgb = QByteArray();
	loadStatus = false;
	FileLoader fileLoader(filePath, rgb, loadStatus);

	// Load File
	fileLoader.start();

	// Update UI
	while (fileLoader.isRunning()) {
		QCoreApplication::processEvents();
	}

	// Waite Thread
	fileLoader.wait();
}