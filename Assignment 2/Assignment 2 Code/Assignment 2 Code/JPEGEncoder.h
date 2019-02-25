#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

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
	QVector<QVector<int>> r;
	QVector<QVector<int>> g;
	QVector<QVector<int>> b;

	// YCbCr Color Spaces
	QVector<QVector<float>> y;
	QVector<QVector<float>> cb;
	QVector<QVector<float>> cr;

	// Function
	void RGBToYCrCb();
	QVector<QVector<float>> DiscreteCosinTransform(QVector<QVector<float>> matrix);
	void PrintGrayScale(QVector<QVector<int>> grayScale);
};