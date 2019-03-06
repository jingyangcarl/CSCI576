#include "IDWTProcessor.h"

IDWTProcessor::IDWTProcessor(QVector<QVector<float>> const & matrix) :
	matrix(matrix) {
	resultMatrix = matrix;
}

QVector<QVector<float>> IDWTProcessor::GetResultMatrix() {
	return resultMatrix;
}

/*
Description:
	This function is used to perform wavelet transform on rows
	[3 7 -1 -1] -> [2 4 6 8]
Input:
	@ int size: the size of the matrix, since we use the same matrix but its different size
Output:
	@
*/
void IDWTProcessor::InverseDiscreteWaveletTransformRow(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size / 2; j++) {
			resultMatrix[i][2 * j + 0] = matrix[i][j] + matrix[i][size / 2 + j];
			resultMatrix[i][2 * j + 1] = matrix[i][j] - matrix[i][size / 2 + j];
		}
	}
}

/*
Description:
	This function is used to perform inverse wavelet transform on columns
	[3 7 -1 -1]^T -> [2 4 6 8]^T
Input:
	@ int size: the size of the matrix, since we use the same matrix but its different size
Output:
	@
*/
void IDWTProcessor::InverseDiscreteWaveletTransformCol(int size) {
	QVector<QVector<float>> matrix = resultMatrix;
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size / 2; i++) {
			resultMatrix[2 * i + 0][j] = matrix[i][j] + matrix[size / 2 + i][j];
			resultMatrix[2 * i + 1][j] = matrix[i][j] - matrix[size / 2 + i][j];
		}
	}
}

/*
Description:
	This function is used to perform inverse wavelet transform recursively
Input:
	@
Output:
	@
*/
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
