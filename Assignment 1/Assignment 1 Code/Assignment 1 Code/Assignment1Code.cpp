#include "Assignment1Code.h"

Assignment1Code::Assignment1Code(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	layoutInitialization();
	widgetInitialization();
	connectionInitialization();

	//frameReader();
	//frameSeparator();
}
