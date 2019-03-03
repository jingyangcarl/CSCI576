#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class JPEGDecoder : public QThread {
public:
	JPEGDecoder(QByteArray & rgb);
	void GetRIDCT();
	void GetGIDCT();
	void GetBIDCT();

protected:
	void run();

private:
	// Variable References
	QByteArray & ycrcb;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// YCbCr Color Spaces
	QVector<QVector<float>> y;
	QVector<QVector<float>> cb;
	QVector<QVector<float>> cr;

	// Function
	QVector<QVector<float>> InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTDequantization_8(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> SquareBlockInverseDCT(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> Expand_2(QVector<QVector<float>> & matrix);
	void YCrCbToRGB();
};