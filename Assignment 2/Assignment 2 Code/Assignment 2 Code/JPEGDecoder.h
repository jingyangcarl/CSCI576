#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class JPEGDecoder : public QThread {
public:
	JPEGDecoder(QByteArray & rgb);
	void SetGear(int gear);
	void GetRIDCT();
	void GetGIDCT();
	void GetBIDCT();
	QByteArray RGBSerielization();

private:
	// Variable References
	const QByteArray & rgb;

	// Paramete
	int gear;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	QVector<QVector<float>> ZigZagDeserielization(QByteArray zigzag, int gear);
	void RGBZigZagDeserielization(int gear);
	QVector<QVector<float>> InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTDequantization_8(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> SquareBlockInverseDCT(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> Expand_2(QVector<QVector<float>> & matrix);
	void YCbCrToRGB();

protected:
	void run();
};