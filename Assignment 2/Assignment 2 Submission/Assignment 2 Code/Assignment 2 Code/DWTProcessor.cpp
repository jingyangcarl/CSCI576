#include "DWTProcessor.h"

DWTProcessor::DWTProcessor(QVector<QVector<float>> const & matrix) :
	matrix(matrix) {
	resultMatrix = matrix;
}

QVector<QVector<float>> DWTProcessor::GetResultMatrix() {
	return resultMatrix;
}

/*
Description:
	This function is used to perform wavelet transform on rows
	[2 4 6 8] -> [3 7 -1 -1]
Input:
	@ int size: the size of the matrix, since we use the same matrix but its different size
Output:
	@
*/
void DWTProcessor::DiscreteWaveletTransformRow(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size / 2; j++) {
			resultMatrix[i][j] = (matrix[i][2 * j] + matrix[i][2 * j + 1]) / 2;
			resultMatrix[i][size / 2 + j] = (matrix[i][2 * j] - matrix[i][2 * j + 1]) / 2;
		}
	}
}

/*
Description:
	This function is used to perform wavelet transform on columns
	[2 4 6 8]^T -> [3 7 -1 -1]^T
Input:
	@ int size: the size of the matrix, since we use the same matrix but its different size
Output:
	@
*/
void DWTProcessor::DiscreteWaveletTransformCol(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size / 2; i++) {
			resultMatrix[i][j] = (matrix[2 * i][j] + matrix[2 * i + 1][j]) / 2;
			resultMatrix[size / 2 + i][j] = (matrix[2 * i][j] - matrix[2 * i + 1][j]) / 2;
		}
	}
}

/*
Description:
	This function is used to perform wavelet transform recursively
Input:
	@
Output:
	@
*/
void DWTProcessor::DiscreteWaveletTransform() {
	int size = matrix.size();
	while (size != 1) {
		DiscreteWaveletTransformRow(size);
		DiscreteWaveletTransformCol(size);
		size /= 2;
	}
}

void DWTProcessor::run() {
	DiscreteWaveletTransform();
}
