#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder(QByteArray & rgb, bool & encodeStatus) :
	rgb(rgb), encodeStatus(encodeStatus) {

	r = QVector<QVector<int>>(512, QVector<int>(512, 0));
	g = QVector<QVector<int>>(512, QVector<int>(512, 0));
	b = QVector<QVector<int>>(512, QVector<int>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			r[i][j] = (uchar)rgb[0 * 512 * 512 + i * 512 + j];
			g[i][j] = (uchar)rgb[1 * 512 * 512 + i * 512 + j];
			b[i][j] = (uchar)rgb[2 * 512 * 512 + i * 512 + j];
		}
	}
}

void JPEGEncoder::run() {
	// RGBToYCrCb();

	QVector<QVector<float>> test(4, QVector<float>(4, 0));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			test[i][j] = r[i][j];
		}
	}

	test = DiscreteCosinTransform(test);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			r[i][j] = test[i][j];
		}
	}

	PrintGrayScale(r);
}

void JPEGEncoder::RGBToYCrCb() {
	// convert rgb color space to ycbcr color space

	y = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cb = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cr = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			y[i][j] = 0.2989*r[i][j] + 0.5866*g[i][j] + 0.1145*b[i][j];
			cb[i][j] = -0.1687*r[i][j] - 0.3313*g[i][j] + 0.5000*b[i][j];
			cr[i][j] = 0.5000*r[i][j] - 0.4184*g[i][j] - 0.0816*b[i][j];
		}
	}
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
			matrixDCT[u][v] *= 1.0 / 2.0 * (u == 0 ? 1.0/sqrt(2) : 1) * (v == 0 ? 1.0/sqrt(2) : 1);
		}
	}

	return matrixDCT;

	// tested on case 
	// suppose a = [
	// 226 226 223 223;
	// 226 226 223 223;
	// 226 226 223 223;
	// 226 226 223 223]
	// A = dct2(a) from octave will generate
	// 898.00000 5.54328 0.00000 -2.29610
	// 0.00000 0.00000 0.00000 0.00000
	// 0.00000 0.00000 0.00000 0.00000
	// 0.00000 0.00000 0.00000 0.00000
	// A = DiscreteCosinTransform(a) will generate
	// 898.000000 5.54326534 -7.94973573e-07 -2.29609966
	// -1.59962792e-06 - 5.62131220e-07 3.68519272e-06 - 5.62131220e-07
	// - 7.94973573e-07 3.68519272e-06 - 2.84217094e-14 - 2.13271096e-06
	// 4.11387919e-06 - 5.62131220e-07 - 4.04005959e-06 2.46947980e-06
}

void JPEGEncoder::PrintGrayScale(QVector<QVector<int>> grayScale) {
	// print gray scale image
	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			rgb[0 * 512 * 512 + i * 512 + j] = grayScale[i][j];
			rgb[1 * 512 * 512 + i * 512 + j] = grayScale[i][j];
			rgb[2 * 512 * 512 + i * 512 + j] = grayScale[i][j];
		}
	}
}
