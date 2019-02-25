#pragma once
#include <qthread.h>
#include <qvector.h>

class JPEGDecoder : public QThread {
public:
	JPEGDecoder(QByteArray & rgb, bool &decodeStatus);

protected:
	void run();

private:
	// Variable References
	QByteArray & rgb;
	bool &decodeStatus;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// YCbCr Color Spaces
	QVector<QVector<float>> y;
	QVector<QVector<float>> cb;
	QVector<QVector<float>> cr;
};