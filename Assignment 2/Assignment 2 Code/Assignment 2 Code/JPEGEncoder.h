#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>
#include <qbitarray.h>
#include <qmap.h>
#include <queue>

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
	QVector<QVector<float>> Shrink_2(QVector<QVector<float>> & matrix);
	QVector<QVector<float>> DiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTQuantization_8(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> BlockDCT_512(QVector<QVector<float>> const & matrix);
	QVector<float> ZigZagSeries(QVector<QVector<float>> const & matrix);
	QMap<QString, QString> HuffmanEncode(QMap<QString, int> input);
	QString VLIEncode(int number);
	QString EntropyEncode_512(QVector<QVector<float>> matrix);
	void PrintGrayScale(QVector<QVector<float>> const & grayScale);
};