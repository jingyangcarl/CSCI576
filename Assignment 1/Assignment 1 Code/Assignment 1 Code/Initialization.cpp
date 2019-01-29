#include "Assignment1Code.h"

void Assignment1Code::layoutInitialization() {
	ui.gridLayout->setColumnStretch(0, 4);
	ui.gridLayout->setColumnStretch(1, 1);
}

void Assignment1Code::widgetInitialization() {
	ui.label_image->setText("label_image");
	ui.label_status->setText("");
}

void Assignment1Code::connectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(loadFile()));
	connect(ui.pushButton_play, SIGNAL(clicked()), this, SLOT(play()));
}