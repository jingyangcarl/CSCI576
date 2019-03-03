#include "JPEGDecoder.h"

JPEGDecoder::JPEGDecoder(QByteArray & ycrcb) :
	ycrcb(ycrcb) {
	y = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cr = QVector<QVector<float>>(256, QVector<float>(256, 0));
	cb = QVector<QVector<float>>(256, QVector<float>(256, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			y[i][j] = (uchar)ycrcb[i * 512 + j];
			cr[i / 2][j / 2] = (uchar)ycrcb[512 * 512 + (i / 2) * 256 + (j / 2)];
			cb[i / 2][j / 2] = (uchar)ycrcb[512 * 512 + 256 * 256 + (i / 2) * 256 + (j / 2)];
		}
	}
}

void JPEGDecoder::GetRIDCT() {
	QByteArray rByte(r.size() * r[0].size(), 0);
	if (r.size()) {
		for (int i = 0; i < r.size(); i++)
			for (int j = 0; j < r[0].size(); j++)
				rByte.append(r[i][j]);
	}
}

void JPEGDecoder::GetGIDCT() {
	QByteArray gByte(g.size() * g[0].size(), 0);
	if (g.size()) {
		for (int i = 0; i < g.size(); i++)
			for (int j = 0; j < g[0].size(); j++)
				gByte.append(g[i][j]);
	}
}

void JPEGDecoder::GetBIDCT() {
	QByteArray bByte(b.size() * b[0].size(), 0);
	if (b.size()) {
		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < b[0].size(); j++)
				bByte.append(b[i][j]);
	}
}

QByteArray JPEGDecoder::RGBSerielization() {
	QByteArray rgb;
	for (int i = 0; i < r.size(); i++)
		for (int j = 0; j < r[0].size(); j++)
			rgb.append(r[i][j]);
	for (int i = 0; i < g.size(); i++)
		for (int j = 0; j < g[0].size(); j++)
			rgb.append(g[i][j]);
	for (int i = 0; i < b.size(); i++)
		for (int j = 0; j < b[0].size(); j++)
			rgb.append(b[i][j]);
	return rgb;
}

void JPEGDecoder::run() {
	// Conduct iDCT
	y = SquareBlockInverseDCT(y);
	cr = SquareBlockInverseDCT(cr);
	cb = SquareBlockInverseDCT(cb);

	// Decode 4:2:0
	cr = Expand_2(cr);
	cb = Expand_2(cb);

	// Convert YCrCb color space to RGB color spac
	YCrCbToRGB();
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

/*
Description:
	This function is used to dequantize the given 8 by 8 matrix using the quantization table,
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
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix that needs to be dequantized
Output:
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix after dequantization
*/
QVector<QVector<float>> JPEGDecoder::DCTDequantization_8(QVector<QVector<float>> const & matrix) {
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
		QVector<QVector<float>> deQuantizedMatrix(8, QVector<float>(8, 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				deQuantizedMatrix[i][j] = round(matrix[i][j] * (float)quantizationTable[i][j]);
			}
		}
		return deQuantizedMatrix;
	}
	else return QVector<QVector<float>>();
}

/*
Description:
	This function is used to divide an given 512 by 512 matrix into several blocks of size 8 by 8.
	For each block, an InverseDiscreteCosinTransform(DCT) is conducted to transform the block from frequency domain to time domain.
	Next, a dequantization is performed on the block using the quantization table
Input:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix needed to be transformed
Output:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix after block DCT transformation and dequantization
*/
QVector<QVector<float>> JPEGDecoder::SquareBlockInverseDCT(QVector<QVector<float>> const & matrix) {
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
				subMatrix = InverseDiscreteCosinTransform(subMatrix);
				subMatrix = DCTDequantization_8(subMatrix);
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						resultMatrix[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
			}
		}
		return resultMatrix;
	}
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
	This function is used to transform YCrCb color space to RGB color space
Input:
	@
Output:
	@
*/
void JPEGDecoder::YCrCbToRGB() {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			r[i][j] = y[i][j] + (cr[i][j] - 128) * 1.40200;
			g[i][j] = y[i][j] + (cb[i][j] - 128) * -0.34414 + (cr[i][j] - 128) * -0.71414;
			b[i][j] = y[i][j] + (cb[i][j] - 128) * 1.77200;
		}
	}
}