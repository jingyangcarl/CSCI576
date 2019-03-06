#include "DWTProcessor.h"

DWTProcessor::DWTProcessor(QVector<QVector<float>> const & matrix) :
	matrix(matrix) {
	resultMatrix = matrix;
}

QVector<QVector<float>> DWTProcessor::GetResultMatrix() {
	return resultMatrix;
}

void DWTProcessor::DiscreteWaveletTransformRow(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size() / 2; j++) {
			resultMatrix[i][j] = (matrix[i][2 * j] + matrix[i][2 * j + 1]) / 2;
			resultMatrix[i][matrix[i].size() / 2 + j] = (matrix[i][2 * j] - matrix[i][2 * j + 1]) / 2;
		}
	}
}

void DWTProcessor::DiscreteWaveletTransformCol(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int j = 0; j < matrix[0].size(); j++) {
		for (int i = 0; i < matrix.size() / 2; i++) {
			resultMatrix[i][j] = (matrix[2 * i][j] + matrix[2 * i + 1][j]) / 2;
			resultMatrix[matrix[0].size() / 2 + i][j] = (matrix[2 * i][j] - matrix[2 * i + 1][j]) / 2;
		}
	}
}

void DWTProcessor::DiscreteWaveletTransform() {
	int size = matrix.size();
	while (size != 1) {
		DiscreteWaveletTransformRow(size);
		DiscreteWaveletTransformCol(size);
		size /= 2;
	}
}

void DWTProcessor::run() {
}
