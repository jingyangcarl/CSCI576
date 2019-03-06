#include "JP2Decoder.h"

JP2Decoder::JP2Decoder(QByteArray & rgb) :
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

void JP2Decoder::InverseDiscreteWaveletTransformRow(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int size) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size() / 2; j++) {
			resultMatrix[i][2 * j + 0] = matrix[i][j] + matrix[i][matrix[0].size() / 2 + j];
			resultMatrix[i][2 * j + 1] = matrix[i][j] - matrix[i][matrix[0].size() / 2 + j];
		}
	}
}

void JP2Decoder::InverseDiscreteWaveletTransformCol(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int size) {
	for (int j = 0; j < matrix[0].size(); j++) {
		for (int i = 0; i < matrix.size() / 2; i++) {
			resultMatrix[2 * i + 0][j] = matrix[i][j] + matrix[matrix[0].size() / 2 + i][j];
			resultMatrix[2 * i + 1][j] = matrix[i][j] - matrix[matrix[0].size() / 2 + i][j];
		}
	}
}

QVector<QVector<float>> JP2Decoder::InverseDiscreteWaveletTransform(QVector<QVector<float>>& matrix) {
	QVector<QVector<float>> resultMatrix = matrix;
	int size = 1;
	while (size != matrix.size()) {
		InverseDiscreteWaveletTransformCol(matrix, resultMatrix, size);
		InverseDiscreteWaveletTransformRow(matrix, resultMatrix, size);
		size *= 2;
	}
	return resultMatrix;
}

void JP2Decoder::run() {
}
