#pragma once
#include <qthread.h>
#include <qvector.h>

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
	void DiscreteCosinTransform(QVector<QVector<int>> matrix);
};