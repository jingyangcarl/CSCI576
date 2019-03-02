#include "Assignment2Code.h"

void Assignment2Code::ConnectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(PushButtonLoad()));
	connect(ui.pushButton_jpeg_encoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGEncoder()));
	connect(ui.pushButton_jpeg_decoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGDecoder()));
	connect(ui.pushButton_test, SIGNAL(clicked()), this, SLOT(PushButtonTest()));
	connect(ui.pushButton_dcty, SIGNAL(clicked()), this, SLOT(PushButtonDCTY()));
	connect(ui.pushButton_dctcr, SIGNAL(clicked()), this, SLOT(PushButtonDCTCr()));
	connect(ui.pushButton_dctcb, SIGNAL(clicked()), this, SLOT(PushButtonDCTCb()));
}