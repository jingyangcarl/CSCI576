#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>

class DCTProcessor : public QThread {
public:
	DCTProcessor(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> GetResultMatrix();

private:
	// Variable References
	QVector<QVector<float>> const & matrix;
	QVector<QVector<float>> resultMatrix;

	// Function
	QVector<QVector<float>> DiscreteCosinTransform(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> DCTQuantization_8(QVector<QVector<float>> const & matrix);
	void SquareBlockDCT();

protected:
	void run();
};