#pragma once
#include <qthread.h>
#include <qvector.h>

class IDWTProcessor : public QThread {
public:
	IDWTProcessor(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> GetResultMatrix();

private:
	// Variable References
	QVector<QVector<float>> const & matrix;
	QVector<QVector<float>> resultMatrix;

	// Function
	void InverseDiscreteWaveletTransformRow(int size);
	void InverseDiscreteWaveletTransformCol(int size);
	void InverseDiscreteWaveletTransform();
	void ColorCheck();

protected:
	void run();
};