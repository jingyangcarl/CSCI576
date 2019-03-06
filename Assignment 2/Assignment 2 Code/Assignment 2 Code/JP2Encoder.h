#pragma once
#include <qthread.h>
#include <qvector.h>
#include "DWTProcessor.h"

class JP2Encoder : public QThread {
public:
	JP2Encoder(QByteArray &rgb);
	QByteArray GetRDWT();
	QByteArray GetGDWT();
	QByteArray GetBDWT();
	QVector<float> RGBZigZagSerielization();

private:
	// Variable References
	QByteArray & rgb;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	QVector<float> ZigZagSeries(QVector<QVector<float>> const & matrix);

protected:
	void run();
};
