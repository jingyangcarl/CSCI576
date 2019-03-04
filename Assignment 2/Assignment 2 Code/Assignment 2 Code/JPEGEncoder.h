#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>
#include <qbitarray.h>
#include <qmap.h>
#include <queue>
#include "DCTProcessor.h"

class JPEGEncoder : public QThread {
public:
	JPEGEncoder(QByteArray &rgb);
	QByteArray GetYDCT();
	QByteArray GetCrDCT();
	QByteArray GetCbDCT();
	QByteArray GetRDCT();
	QByteArray GetGDCT();
	QByteArray GetBDCT();
	QByteArray YCrCbSerielization();
	QByteArray YCrCbZigZagSerielization();
	QByteArray RGBZigZagSerielization();

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
	QByteArray ZigZagSeries(QVector<QVector<float>> const & matrix);

	QMap<QString, QString> HuffmanEncode(QMap<QString, int> input);
	QString VLIEncode(int number);

protected:
	void run();
};