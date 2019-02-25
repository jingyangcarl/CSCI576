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

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			y[i][j] = 0.2989*r[i][j] + 0.5866*g[i][j] + 0.1145*b[i][j];
			cb[i][j] = -0.1687*r[i][j] - 0.3313*g[i][j] + 0.5000*b[i][j];
			cr[i][j] = 0.5000*r[i][j] - 0.4184*g[i][j] - 0.0816*b[i][j];
		}
	}
}

void JPEGEncoder::DiscreteCosinTransform(QVector<QVector<int>> matrix) {

}
