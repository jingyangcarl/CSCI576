#include "Assignment2Code.h"

Assignment2Code::Assignment2Code(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	ConnectionInitialization();
}