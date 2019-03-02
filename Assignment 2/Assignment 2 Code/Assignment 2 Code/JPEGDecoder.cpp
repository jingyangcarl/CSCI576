#include "JPEGDecoder.h"

JPEGDecoder::JPEGDecoder(QByteArray & rgb, bool & decodeStatus) :
	rgb(rgb), decodeStatus(decodeStatus) {
}

void JPEGDecoder::run() {

}

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

QVector<QVector<float>> JPEGDecoder::InverseDiscreteCosinTransform(QVector<QVector<float>> const & matrix) {
	return QVector<QVector<float>>();
}

QVector<QVector<float>> JPEGDecoder::DCTDequantization_8(QVector<QVector<float>> const & matrix) {
	return QVector<QVector<float>>();
}

QVector<QVector<float>> JPEGDecoder::SquareBlockInverseDCT(QVector<QVector<float>> const & matrix) {
	return QVector<QVector<float>>();
}
