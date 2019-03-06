#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class DWTProcessor : public QThread {
public:
	DWTProcessor(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> GetResultMatrix();

private:
	// Variable References
	QVector<QVector<float>> const & matrix;
	QVector<QVector<float>> resultMatrix;

	// Function
	void DiscreteWaveletTransformRow(int size);
	void DiscreteWaveletTransformCol(int size);
	void DiscreteWaveletTransform();

protected:
	void run();
};