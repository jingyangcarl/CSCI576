#include "Assignment1Code.h"

void Assignment1Code::layoutInitialization() {
	ui.gridLayout->setColumnStretch(0, 4);
	ui.gridLayout->setColumnStretch(1, 1);
}

void Assignment1Code::widgetInitialization() {
	// set lable_image
	ui.label_image->setText("label_image");
	// set lable status
	ui.label_status->setText("");
	// set width scaler
	ui.horizontalSlider_width_scale->setMinimum(0);
	ui.horizontalSlider_width_scale->setMaximum(100);
	ui.horizontalSlider_width_scale->setValue(100);
	ui.label_width_scale_val->setText(QString::number(100));
	// set height scaler
	ui.horizontalSlider_height_scale->setMinimum(0);
	ui.horizontalSlider_height_scale->setMaximum(100);
	ui.horizontalSlider_height_scale->setValue(100);
	ui.label_height_scale_val->setText(QString::number(100));
	// set fps scaler
	ui.horizontalSlider_fps_scale->setMinimum(0);
	ui.horizontalSlider_fps_scale->setMaximum(2.0);
	ui.horizontalSlider_fps_scale->setValue(1.0);
	ui.label_fps_scale_val->setText(QString::number(1.0));
}

void Assignment1Code::connectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(loadFile()));
	connect(ui.pushButton_play, SIGNAL(clicked()), this, SLOT(play()));
}