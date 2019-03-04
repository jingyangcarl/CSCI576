#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class IDCTProcessor : public QThread {
public:
	IDCTProcessor(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> GetResultMatrix();

private:
	// Variable References
	QVector<QVector<float>> const & matrix;
	QVector<QVector<float>> resultMatrix;

	// Function
	QVector<QVector<float>> InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTDequantization_8(QVector<QVector<float>> const & matrix);
	void SquareBlockInverseDCT();

protected:
	void run();
};