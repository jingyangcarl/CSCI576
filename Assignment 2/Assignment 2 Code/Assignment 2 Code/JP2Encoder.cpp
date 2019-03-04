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

void JP2Encoder::DiscreteWaveletTransformRow(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int row) {

}

void JP2Encoder::DiscreteWaveletTransformCol(QVector<QVector<float>> const & matrix, QVector<QVector<float>>& resultMatrix, int row) {

}

QVector<QVector<float>> JP2Encoder::DiscreteWaveletTransform(QVector<QVector<float>>& matrix) {
	QVector<QVector<float>> resultMatrix = matrix;
	DiscreteWaveletTransform(resultMatrix);
}

void JP2Encoder::run() {

}
