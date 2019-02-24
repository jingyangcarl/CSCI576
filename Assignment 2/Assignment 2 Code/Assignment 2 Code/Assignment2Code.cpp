#include "Assignment2Code.h"

Assignment2Code::Assignment2Code(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
}

void Assignment2Code::TextBrowserPrint(QString output) {
	ui.textBrowser_output->append(output + '\n');
}
