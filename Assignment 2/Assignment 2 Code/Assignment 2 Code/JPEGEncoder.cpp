#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder(QByteArray & rgb, bool & encodeStatus) :
	rgb(rgb), encodeStatus(encodeStatus) {

	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			r[i][j] = rgb[0 * 512 * 512 + i * 512 + j];
			g[i][j] = rgb[1 * 512 * 512 + i * 512 + j];
			b[i][j] = rgb[2 * 512 * 512 + i * 512 + j];
		}
	}
}

void JPEGEncoder::run() {
	RGBToYCrCb();

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			rgb[0 * 512 * 512 + i * 512 + j] = y[i][j];
			rgb[1 * 512 * 512 + i * 512 + j] = y[i][j];
			rgb[2 * 512 * 512 + i * 512 + j] = y[i][j];
		}
	}
}

void JPEGEncoder::RGBToYCrCb() {
	// convert rgb color space to ycbcr color space

	y = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cb = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cr = QVector<QVector<float>>(512, QVector<float>(512, 0));

	PrintGrayScale(y);
}

QVector<QVector<float>> JPEGEncoder::DiscreteCosinTransform(QVector<QVector<float>> matrix) {
	// Basic DCT for a M by N matrix, where M denotes the number of rows, and N denotes the number of columns
	// the general equation for a 2D (M by N) DCT is defined as

	QVector<QVector<float>> matrixDCT = matrix;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int u = 0; u < m; u++) {
		for (int v = 0; v < n; v++) {
			matrixDCT[u][v] = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					matrixDCT[u][v] += matrix[i][j] * cos(M_PI/((float)m)*(i + 1.0/2.0) * u) * cos(M_PI/((float)n)*(j + 1.0/2.0) * v);
				}
			}
			matrixDCT[u][v] *= 1.0 / 4.0 * (u == 0 ? 1.0/sqrt(2) : 1) * (v == 0 ? 1.0/sqrt(2) : 1);
		}
	}

	return matrixDCT;
}

void JPEGEncoder::PrintGrayScale(QVector<QVector<float>> grayScale) {
	// print gray scale image
	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			rgb[0 * 512 * 512 + i * 512 + j] = grayScale[i][j];
			rgb[1 * 512 * 512 + i * 512 + j] = grayScale[i][j];
			rgb[2 * 512 * 512 + i * 512 + j] = grayScale[i][j];
		}
	}
}
