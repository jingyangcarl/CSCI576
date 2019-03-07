#include "JPEGDecoder.h"

JPEGDecoder::JPEGDecoder(QVector<float>& rgb) :
	rgb(rgb) {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));
}

JPEGDecoder::JPEGDecoder(QVector<float> & rgb, int gear) :
	rgb(rgb), gear(gear) {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));
}

void JPEGDecoder::SetGear(int gear) {
	this->gear = gear;
}

/*
Description:
	This function is used to serielize rgb channels for main bus
Input:
	@
Output:
	@ QByteArray rgb: rgb byte array used for main bus
*/
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
QVector<QVector<float>> JPEGDecoder::ZigZagDeserielization(QVector<float> zigzag, int gear) {
	if (zigzag.size() == 0) return QVector<QVector<float>>();
	QVector<QVector<float>> matrix(sqrt(zigzag.size()), QVector<float>(sqrt(zigzag.size()), 0));
	QVector<float>::const_iterator iter = zigzag.begin();
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

void JPEGDecoder::run() {

	RGBZigZagDeserielization(gear);

	IDCTProcessor idctRProcessor(r);
	IDCTProcessor idctGProcessor(g);
	IDCTProcessor idctBProcessor(b);

	idctRProcessor.start();
	idctGProcessor.start();
	idctBProcessor.start();

	idctRProcessor.wait();
	idctGProcessor.wait();
	idctBProcessor.wait();

	r = idctRProcessor.GetResultMatrix();
	g = idctGProcessor.GetResultMatrix();
	b = idctBProcessor.GetResultMatrix();
}