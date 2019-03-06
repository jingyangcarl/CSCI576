#include "IDWTProcessor.h"

IDWTProcessor::IDWTProcessor(QVector<QVector<float>> const & matrix) :
	matrix(matrix) {
	resultMatrix = matrix;
}

QVector<QVector<float>> IDWTProcessor::GetResultMatrix() {
	return resultMatrix;
}

void IDWTProcessor::InverseDiscreteWaveletTransformRow(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size / 2; j++) {
			resultMatrix[i][2 * j + 0] = matrix[i][j] + matrix[i][size / 2 + j];
			resultMatrix[i][2 * j + 1] = matrix[i][j] - matrix[i][size / 2 + j];
		}
	}
}

void IDWTProcessor::InverseDiscreteWaveletTransformCol(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size / 2; i++) {
			resultMatrix[2 * i + 0][j] = matrix[i][j] + matrix[size / 2 + i][j];
			resultMatrix[2 * i + 1][j] = matrix[i][j] - matrix[size / 2 + i][j];
		}
	}
}

void IDWTProcessor::InverseDiscreteWaveletTransform() {
	int size = 1;
	while (size != matrix.size()) {
		size *= 2;
		InverseDiscreteWaveletTransformCol(size);
		InverseDiscreteWaveletTransformRow(size);
	}
}

void IDWTProcessor::run() {
	InverseDiscreteWaveletTransform();
}
