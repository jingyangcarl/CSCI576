#include "DCTProcessor.h"

DCTProcessor::DCTProcessor(QVector<QVector<float>> const & matrix) :
	matrix(matrix) {
}

QVector<QVector<float>> DCTProcessor::GetResultMatrix() {
	return resultMatrix;
}

/*
Description:
	This function is used to transform any given matrix from time domain to frequency domain
	Reference Link: https://www.mathworks.com/help/images/ref/dct2.html
Input:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix, which needed to be transform to frequency domain
Output:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix representing frequency infomation
*/
QVector<QVector<float>> DCTProcessor::DiscreteCosinTransform(QVector<QVector<float>> const & matrix) {
	QVector<QVector<float>> matrixDCT = matrix;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int u = 0; u < m; u++) {
		for (int v = 0; v < n; v++) {
			matrixDCT[u][v] = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					matrixDCT[u][v] += matrix[i][j] * cos(M_PI / ((float)m)*(i + 1.0 / 2.0) * u) * cos(M_PI / ((float)n)*(j + 1.0 / 2.0) * v);
				}
			}
			matrixDCT[u][v] *= sqrt(2.0 / m) * sqrt(2.0 / n) * (u == 0 ? 1.0 / sqrt(2) : 1) * (v == 0 ? 1.0 / sqrt(2) : 1);
		}
	}

	return matrixDCT;
}

/*
Description:
	This function is used to quantize the given 8 by 8 matrix using the quantization table,
	where the quantization table is:
	quantizationTable = {
		{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{14, 17, 22, 29, 51, 87, 80, 62},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{72, 92, 96, 98, 112, 100, 103, 99}
	}
Input:
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix that needs to be quantized
Output:
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix after quantization
*/
QVector<QVector<float>> DCTProcessor::DCTQuantization_8(QVector<QVector<float>> const & matrix) {
	int const quantizationTable[8][8] = {
		{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{14, 17, 22, 29, 51, 87, 80, 62},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{72, 92, 96, 98, 112, 100, 103, 99}
	};

	if (matrix.size() == 8 && matrix[0].size() == 8) {
		QVector<QVector<float>> quantizedMatrix(8, QVector<float>(8, 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				quantizedMatrix[i][j] = round(matrix[i][j] / (float)quantizationTable[i][j]);
			}
		}
		return quantizedMatrix;
	}
	else return QVector<QVector<float>>();
}

/*
Description:
	This function is used to divide an given 512 by 512 matrix into several blocks of size 8 by 8.
	For each block, a DiscreteCosinTransform(DCT) is conducted to transform the block from time domain to frequency domain.
	Next, a quantization is performed on the block using the quantization table
Input:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix needed to be transformed
Output:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix after block DCT transformation and quantization
*/
void DCTProcessor::SquareBlockDCT() {
	if (matrix.size() % 8 != 0) return;
	else if (matrix[0].size() % 8 != 0) return;
	else {
		resultMatrix = QVector<QVector<float>>(matrix.size(), QVector<float>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size() / 8; i++) {
			for (int j = 0; j < matrix[0].size() / 8; j++) {
				QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						subMatrix[ii][jj] = matrix[i * 8 + ii][j * 8 + jj];
				subMatrix = DiscreteCosinTransform(subMatrix);
				// subMatrix = DCTQuantization_8(subMatrix);
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						resultMatrix[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
			}
		}
	}
}

void DCTProcessor::run() {
	SquareBlockDCT();
}