#include "JP2Encoder.h"

JP2Encoder::JP2Encoder(QByteArray & rgb) :
	rgb(rgb) {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			r[i][j] = (uchar)rgb[0 * 512 * 512 + i * 512 + j];
			g[i][j] = (uchar)rgb[1 * 512 * 512 + i * 512 + j];
			b[i][j] = (uchar)rgb[2 * 512 * 512 + i * 512 + j];
		}
	}
}

void JP2Encoder::DiscreteWaveletTransformRow(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int size) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size() / 2; j++) {
			resultMatrix[i][j] = (matrix[i][2 * j] + matrix[i][2 * j + 1]) / 2;
			resultMatrix[i][matrix[i].size() / 2 + j] = (matrix[i][2 * j] - matrix[i][2 * j + 1]) / 2;
		}
	}
}

void JP2Encoder::DiscreteWaveletTransformCol(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int size) {
	for (int j = 0; j < matrix[0].size(); j++) {
		for (int i = 0; i < matrix.size() / 2; i++) {
			resultMatrix[i][j] = (matrix[2 * i][j] + matrix[2 * i + 1][j]) / 2;
			resultMatrix[matrix[0].size() / 2 + i][j] = (matrix[2 * i][j] - matrix[2 * i + 1][j]) / 2;
		}
	}
}

QVector<QVector<float>> JP2Encoder::DiscreteWaveletTransform(QVector<QVector<float>>& matrix) {
	QVector<QVector<float>> resultMatrix = matrix;
	int size = matrix.size();
	while (size != 1) {
		DiscreteWaveletTransformRow(matrix, resultMatrix, size);
		DiscreteWaveletTransformCol(matrix, resultMatrix, size);
		size /= 2;
	}
	return resultMatrix;
}

void JP2Encoder::run() {
}