#pragma once
#include <qthread.h>
#include <qimage.h>

class AntiAliasingOperator : public QThread {
public:
	AntiAliasingOperator(QImage &srcImage, QImage&desImage);
	void LowPassConvolution();


protected:
	void run();

private:
	QImage &srcImage;
	QImage &desImage;
};