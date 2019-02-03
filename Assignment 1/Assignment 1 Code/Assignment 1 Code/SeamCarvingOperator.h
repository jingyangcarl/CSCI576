#pragma once
#include <qthread.h>
#include <qimage.h>

class SeamCarvingOperator : public QThread {
public:
	SeamCarvingOperator(QImage &srcImage, QImage &desImage);

	void ToGrayScale();
	void CalculateGradiant();
	void OutputGrayScale();
	void OutputGradiant();

protected:
	void run();

private:
	QImage &srcImage;
	QImage &desImage;
	QVector<QVector<float>> grayImage;
	QVector<QVector<float>> G;
};