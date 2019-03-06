#include "Assignment2Code.h"

void Assignment2Code::ConnectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(PushButtonLoad()));
	connect(ui.pushButton_jpeg_encoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGEncoder()));
	connect(ui.pushButton_jpeg_decoder, SIGNAL(clicked()), this, SLOT(PushButtonJPEGDecoder()));
	connect(ui.pushButton_jp2_encoder, SIGNAL(clicked()), this, SLOT(PushButtonJP2Encoder()));
	connect(ui.pushButton_jp2_decoder, SIGNAL(clicked()), this, SLOT(PushButtonJP2Decoder()));
	connect(ui.pushButton_test, SIGNAL(clicked()), this, SLOT(PushButtonTest()));
	connect(ui.pushButton_dctr, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTR()));
	connect(ui.pushButton_dctg, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTG()));
	connect(ui.pushButton_dctb, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTB()));
	connect(ui.pushButton_dwtr, SIGNAL(clicked()), this, SLOT(PushButtonShowDWTR()));
	connect(ui.pushButton_dwtg, SIGNAL(clicked()), this, SLOT(PushButtonShowDWTG()));
	connect(ui.pushButton_dwtb, SIGNAL(clicked()), this, SLOT(PushButtonShowDWTB()));
	connect(ui.pushButton_dcty, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTY()));
	connect(ui.pushButton_dctcr, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTCr()));
	connect(ui.pushButton_dctcb, SIGNAL(clicked()), this, SLOT(PushButtonShowDCTCb()));
	connect(ui.pushButton_original_image, SIGNAL(clicked()), this, SLOT(PushButtonShowOriginalImage()));
	connect(ui.pushButton_jpeg_262144, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_262114()));
	connect(ui.pushButton_jpeg_131072, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_131072()));
	connect(ui.pushButton_jpeg_65535, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_65535()));
	connect(ui.pushButton_jpeg_16384, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_16384()));
	connect(ui.pushButton_jpeg_8192, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_8192()));
	connect(ui.pushButton_jpeg_4096, SIGNAL(clicked()), this, SLOT(PushButtonShowJPEG_4096()));
	connect(ui.pushButton_jp2_262144, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_262114()));
	connect(ui.pushButton_jp2_131072, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_131072()));
	connect(ui.pushButton_jp2_65535, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_65535()));
	connect(ui.pushButton_jp2_16384, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_16384()));
	connect(ui.pushButton_jp2_8192, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_8192()));
	connect(ui.pushButton_jp2_4096, SIGNAL(clicked()), this, SLOT(PushButtonShowJP2_4096()));
	
}