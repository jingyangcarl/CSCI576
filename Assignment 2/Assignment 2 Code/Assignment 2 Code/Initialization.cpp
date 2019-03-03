#include "Assignment2Code.h"

void Assignment2Code::ConnectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(PushButtonLoad()));
	connect(ui.pushButton_jpeg_encoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGEncoder()));
	connect(ui.pushButton_jpeg_decoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGDecoder()));
	connect(ui.pushButton_test, SIGNAL(clicked()), this, SLOT(PushButtonTest()));
	connect(ui.pushButton_dcty, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTY()));
	connect(ui.pushButton_dctcr, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTCr()));
	connect(ui.pushButton_dctcb, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTCb()));
	connect(ui.pushButton_original_image, SIGNAL(clicked()), this, SLOT(PushButtonShowOriginalImage()));
}