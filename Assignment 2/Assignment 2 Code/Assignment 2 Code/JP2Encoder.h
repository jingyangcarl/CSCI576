#pragma once
#include <qthread.h>
#include <qvector.h>

class JP2Encoder : public QThread {
public:
	JP2Encoder(QByteArray &rgb);
private:
	// Variable References
	QByteArray & rgb;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	void DiscreteWaveletTransformRow(QVector<QVector<float>> const & matrix, QVector<QVector<float>> & resultMatrix, int size);
	void DiscreteWaveletTransformCol(QVector<QVector<float>> const & matrix, QVector<QVector<float>> & resultMatrix, int size);
	QVector<QVector<float>> DiscreteWaveletTransform(QVector<QVector<float>> & matrix);

protected:
	void run();
};
