#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder(QByteArray & rgb, bool & encodeStatus) :
	rgb(rgb), encodeStatus(encodeStatus) {
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

void JPEGEncoder::run() {
	// Convert RGB color space to YCrCb color space
	 RGBToYCrCb();

	y = BlockDCT(y);
	PrintGrayScale(y);
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
					matrixDCT[u][v] += matrix[i][j] * cos(M_PI / ((float)m)*(i + 1.0 / 2.0) * u) * cos(M_PI / ((float)n)*(j + 1.0 / 2.0) * v);
				}
			}
			matrixDCT[u][v] *= sqrt(2.0 / m) * sqrt(2.0 / n) * (u == 0 ? 1.0 / sqrt(2) : 1) * (v == 0 ? 1.0 / sqrt(2) : 1);
		}
	}

	return matrixDCT;
}

QVector<QVector<float>> JPEGEncoder::DCTQuantization(QVector<QVector<float>> matrix) {
	// The input of this function has to be limited to 8 by 8
	// The 8 by 8 DCT quantization table is listed as follows
	// 16, 11, 10, 16, 24, 40, 51, 61
	// 12, 12, 14, 19, 26, 58, 60, 55
	// 14, 13, 16, 24, 40, 57, 69, 56
	// 14, 17, 22, 29, 51, 87, 80, 62
	// 18, 22, 37, 56, 68, 109, 103, 77
	// 24, 35, 55, 64, 81, 104, 113, 92
	// 49, 64, 78, 87, 103, 121, 120, 101
	// 72, 92, 96, 98, 112, 100, 103, 99

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

QVector<QVector<float>> JPEGEncoder::BlockDCT(QVector<QVector<float>> matrix) {
	// Divide an image into several 8 by 8 blocks and conduct DCT as well as quantization

	if (matrix.size() % 8 != 0) return QVector<QVector<float>>();
	else if (matrix[0].size() % 8 != 0) return QVector<QVector<float>>();
	else {
		QVector<QVector<float>> resultMatrix(matrix.size(), QVector<float>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size() / 8; i++) {
			for (int j = 0; j < matrix[0].size() / 8; j++) {
				QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						subMatrix[ii][jj] = matrix[i * 8 + ii][j * 8 + jj];
				subMatrix = DiscreteCosinTransform(subMatrix);
				subMatrix = DCTQuantization(subMatrix);
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						resultMatrix[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
			}
		}
		return resultMatrix;
	}
}

QBitArray JPEGEncoder::EntropyEncode(QVector<QVector<float>> matrix) {
	// encode submatrix using Huffman and Runlength

	return QBitArray();
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