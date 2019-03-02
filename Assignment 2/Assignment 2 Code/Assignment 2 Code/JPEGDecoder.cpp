#include "JPEGDecoder.h"

JPEGDecoder::JPEGDecoder(QByteArray & rgb, bool & decodeStatus) :
	rgb(rgb), decodeStatus(decodeStatus) {
}

void JPEGDecoder::run() {
}

/*
Description:
	This function is used to expand the matrix to twice of its size
Input:
	@QVector<QVector<float>> matrix: the given color matrix
Output:
	@QVector<QVector<float>> matrix: the matrix after expanding
*/
QVector<QVector<float>> JPEGDecoder::Expand_2(QVector<QVector<float>>& matrix) {
	QVector<QVector<float>> expandMatrix(matrix.size() * 2, QVector<float>(matrix[0].size() * 2));

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			expandMatrix[2 * i][2 * j] = matrix[i][j];
			expandMatrix[2 * i + 1][2 * j] = matrix[i][j];
			expandMatrix[2 * i][2 * j + 1] = matrix[i][j];
			expandMatrix[2 * i + 1][2 * j + 1] = matrix[i][j];
		}
	}

	return expandMatrix;
}

/*
Description:
	This function is used to transform any given matrix from frequency domain to time domain
Input:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix, which needed to be transform to time domain
Output:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix representing time infomation
*/
QVector<QVector<float>> JPEGDecoder::InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix) {
	QVector<QVector<float>> inverseMatrixDCT = matrix;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int u = 0; u < m; u++) {
		for (int v = 0; v < n; v++) {
			inverseMatrixDCT[u][v] = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					inverseMatrixDCT[u][v] += matrix[i][j] * cos(M_PI / ((float)m)*(i + 1.0 / 2.0) * u) * cos(M_PI / ((float)n)*(j + 1.0 / 2.0) * v);
				}
			}
			inverseMatrixDCT[u][v] *= sqrt(2.0 / m) * sqrt(2.0 / n) * (u == 0 ? 1.0 / sqrt(2) : 1) * (v == 0 ? 1.0 / sqrt(2) : 1);
		}
	}

	return inverseMatrixDCT;
}

QVector<QVector<float>> JPEGDecoder::DCTDequantization_8(QVector<QVector<float>> const & matrix) {
	return QVector<QVector<float>>();
}

QVector<QVector<float>> JPEGDecoder::SquareBlockInverseDCT(QVector<QVector<float>> const & matrix) {
	return QVector<QVector<float>>();
}