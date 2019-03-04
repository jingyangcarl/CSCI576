#include "JPEGDecoder.h"

JPEGDecoder::JPEGDecoder(QByteArray & rgb) :
	rgb(rgb), gear(262114) {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));

	RGBZigZagDeserielization(gear);
}

void JPEGDecoder::SetGear(int gear) {
	this->gear = gear;
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

/*
Description:
	This function is used to deseries the given zigzag order byte array of size 64
Input:
	@ QByteArray zigzag: input array of size 64
	@ int gear: indicate the coefficient used for deserielization
Output:
	@ QVector<QVector<float>>: deserilized matrix
*/
QVector<QVector<float>> JPEGDecoder::ZigZagDeserielization(QByteArray zigzag, int gear) {
	if (zigzag.size() == 0) return QVector<QVector<float>>();
	QVector<QVector<float>> matrix(sqrt(zigzag.size()), QVector<float>(sqrt(zigzag.size()), 0));
	QByteArray::const_iterator iter = zigzag.begin();
	bool direction(false);
	for (int i = 0; i < 2 * sqrt(zigzag.size()) - 1; i++) {
		int j = i;
		while (j >= 0) {
			if (direction && (i - j) < matrix.size() && j < matrix.size())
				matrix[i - j][j] = (iter - zigzag.begin() < gear / 262144.0 * zigzag.size()) ? *iter++ : 0;
			if (!direction && j < matrix.size() && (i - j) < matrix.size())
				matrix[j][i - j] = *iter++;
			j--;
		}
		direction = !direction;
	}
	return matrix;
}

/*
Description:
	This function is used to deseries the zigzag order of r channel, g channel, as well as b channel
Input:
	@ int gear: indicate the coefficient used for deserielization
Output:
	@
*/
void JPEGDecoder::RGBZigZagDeserielization(int gear) {
	for (int i = 0; i < r.size() / 8; i++) {
		for (int j = 0; j < r[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix;
			subMatrix = ZigZagDeserielization(rgb.mid(0 * 512 * 512 + i * 64 * 64 + j * 64, 64), gear);
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					r[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
				}
			}
		}
	}
	for (int i = 0; i < g.size() / 8; i++) {
		for (int j = 0; j < g[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix;
			subMatrix = ZigZagDeserielization(rgb.mid(1 * 512 * 512 + i * 64 * 64 + j * 64, 64), gear);
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					g[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
				}
			}
		}
	}
	for (int i = 0; i < b.size() / 8; i++) {
		for (int j = 0; j < b[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix;
			subMatrix = ZigZagDeserielization(rgb.mid(2 * 512 * 512 + i * 64 * 64 + j * 64, 64), gear);
			for (int ii = 0; ii < 8; ii++) {
				for (int jj = 0; jj < 8; jj++) {
					b[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
				}
			}
		}
	}
}

/*
Description: 
	This function is used to transform any given matrix from frequency domain to time domain
	Reference Link: https://www.mathworks.com/help/images/ref/idct2.html
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
					float alpha = (i == 0 ? 1.0 / sqrt(m) : sqrt(2.0 / m)) * (j == 0 ? 1.0 / sqrt(n) : sqrt(2.0 / n));
					inverseMatrixDCT[u][v] += alpha * matrix[i][j] * cos(M_PI / ((float)m)*(u + 1.0 / 2.0) * i) * cos(M_PI / ((float)n)*(v + 1.0 / 2.0) * j);
				}
			}
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
				subMatrix = DCTDequantization_8(subMatrix);
				subMatrix = InverseDiscreteCosinTransform(subMatrix);
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						resultMatrix[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
			}
		}
		return resultMatrix;
	}
}

void JPEGDecoder::run() {
	IDCTProcessor idctRProcessor(r);
	IDCTProcessor idctGProcessor(g);
	IDCTProcessor idctBProcessor(b);

	idctRProcessor.start();
	idctGProcessor.start();
	idctBProcessor.start();

	idctRProcessor.wait();
	idctGProcessor.wait();
	idctBProcessor.wait();

	r = SquareBlockInverseDCT(r);
	g = SquareBlockInverseDCT(g);
	b = SquareBlockInverseDCT(b);
}