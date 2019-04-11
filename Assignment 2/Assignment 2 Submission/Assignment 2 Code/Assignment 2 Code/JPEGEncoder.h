#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>
#include <qmap.h>
#include <queue>
#include "DCTProcessor.h"

class JPEGEncoder : public QThread {
public:
	JPEGEncoder(QByteArray &rgb);
	QByteArray GetRDCT();
	QByteArray GetGDCT();
	QByteArray GetBDCT();
	QByteArray GetYDCT();
	QByteArray GetCbDCT();
	QByteArray GetCrDCT();
	QVector<float> YCrCbZigZagSerielization();
	QVector<float> RGBZigZagSerielization();

private:
	// Variable References
	QByteArray & rgb;

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
	QVector<QVector<float>> Shrink_2(QVector<QVector<float>> & matrix);
	QVector<float> ZigZagSeries(QVector<QVector<float>> const & matrix);

	QMap<QString, QString> HuffmanEncode(QMap<QString, int> input);
	QString VLIEncode(int number);

protected:
	void run();
};