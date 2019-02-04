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
	ui.horizontalSlider_width_scale->setMinimum(1);
	ui.horizontalSlider_width_scale->setMaximum(10);
	ui.horizontalSlider_width_scale->setValue(10);
	ui.label_width_scale_val->setText(QString::number(1));
	// set height scaler
	ui.horizontalSlider_height_scale->setMinimum(1);
	ui.horizontalSlider_height_scale->setMaximum(10);
	ui.horizontalSlider_height_scale->setValue(10);
	ui.label_height_scale_val->setText(QString::number(1));
	// set fps scaler
	ui.horizontalSlider_fps_scale->setMinimum(1);
	ui.horizontalSlider_fps_scale->setMaximum(100);
	ui.horizontalSlider_fps_scale->setValue(50);
	ui.label_fps_scale_val->setText(QString::number(0.5));
	// Anti aliasing switch
	ui.horizontalSlider_anti_aliasing_switch->setMinimum(0);
	ui.horizontalSlider_anti_aliasing_switch->setMaximum(1);
	ui.horizontalSlider_anti_aliasing_switch->setValue(0);
	ui.label_anti_aliasing_switch_val->setText("OFF");
	// Letter Boxing
	ui.horizontalSlider_letter_boxing_switch->setMinimum(0);
	ui.horizontalSlider_letter_boxing_switch->setMaximum(1);
	ui.horizontalSlider_letter_boxing_switch->setValue(0);
	ui.label_letter_boxing_switch_val->setText("OFF");
	// seam carving
	ui.horizontalSlider_seam_carving_switch->setMinimum(0);
	ui.horizontalSlider_seam_carving_switch->setMaximum(1);
	ui.horizontalSlider_seam_carving_switch->setValue(0);
	ui.label_seam_carving_switch_val->setText("OFF");
}

void Assignment1Code::connectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(loadFile()));
	connect(ui.pushButton_play, SIGNAL(clicked()), this, SLOT(play()));
	connect(ui.horizontalSlider_width_scale, SIGNAL(valueChanged(int)), this, SLOT(setWidthScalerVal(int)));
	connect(ui.horizontalSlider_height_scale, SIGNAL(valueChanged(int)), this, SLOT(setHeightScalerVal(int)));
	connect(ui.horizontalSlider_fps_scale, SIGNAL(valueChanged(int)), this, SLOT(setFPSScalerVal(int)));
	connect(ui.horizontalSlider_anti_aliasing_switch, SIGNAL(valueChanged(int)), this, SLOT(setAntiAliasingVal(int)));
	connect(ui.horizontalSlider_letter_boxing_switch, SIGNAL(valueChanged(int)), this, SLOT(setLetterBoxingVal(int)));
	connect(ui.horizontalSlider_seam_carving_switch, SIGNAL(valueChanged(int)), this, SLOT(setSeamCarvingVal(int)));
}