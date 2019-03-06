#pragma once
#include <qthread.h>
#include <qvector.h>

class JP2Decoder : public QThread {
public:
	JP2Decoder(QByteArray &rgb);

private:
	// Variable References
	QByteArray & rgb;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	void InverseDiscreteWaveletTransformRow(QVector<QVector<float>> const & matrix, QVector<QVector<float>> & resultMatrix, int size);
	void InverseDiscreteWaveletTransformCol(QVector<QVector<float>> const & matrix, QVector<QVector<float>> & resultMatrix, int size);
	QVector<QVector<float>> InverseDiscreteWaveletTransform(QVector<QVector<float>> & matrix);

protected:
	void run();
};