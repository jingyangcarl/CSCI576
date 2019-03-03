#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class JPEGDecoder : public QThread {
public:
	JPEGDecoder(QByteArray & ycrcb);
	void SetGear(int gear);
	void GetRIDCT();
	void GetGIDCT();
	void GetBIDCT();
	QByteArray RGBSerielization();

protected:
	void run();

private:
	// Variable References
	const QByteArray & ycrcb;

	// Paramete
	int gear;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// YCbCr Color Spaces
	QVector<QVector<float>> y;
	QVector<QVector<float>> cb;
	QVector<QVector<float>> cr;

	// Function
	QVector<QVector<float>> ZigZagDeserielization(QByteArray zigzag, int gear);
	void YCrCbZigZagDeserielization(int gear);
	QVector<QVector<float>> InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTDequantization_8(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> SquareBlockInverseDCT(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> Expand_2(QVector<QVector<float>> & matrix);
	void YCrCbToRGB();
};