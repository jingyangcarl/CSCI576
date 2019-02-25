#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>
#include <qbitarray.h>

class JPEGEncoder : public QThread {
public:
	JPEGEncoder(QByteArray &rgb, bool &encodeStatus);

protected:
	void run();

private:
	// Variable References
	QByteArray & rgb;
	bool &encodeStatus;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// YCbCr Color Spaces
	QVector<QVector<float>> y;
	QVector<QVector<float>> cb;
	QVector<QVector<float>> cr;

	// Function
	void RGBToYCrCb();
	QVector<QVector<float>> DiscreteCosinTransform(QVector<QVector<float>> matrix);
	QVector<QVector<float>> DCTQuantization(QVector<QVector<float>> matrix);
	QVector<QVector<float>> BlockDCT(QVector<QVector<float>> matrix);
	QBitArray EntropyEncode(QVector<QVector<float>> matrix);
	void PrintGrayScale(QVector<QVector<float>> grayScale);
};