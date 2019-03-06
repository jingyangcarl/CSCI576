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

QByteArray JP2Encoder::GetRDWT() {
	QByteArray rByte(3 * r.size() * r[0].size(), 0);
	if (r.size()) {
		for (int i = 0; i < r.size(); i++)
			for (int j = 0; j < r[0].size(); j++) {
				rByte[0 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
				rByte[1 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
				rByte[2 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
			}
	}
	return rByte;
}

QByteArray JP2Encoder::GetGDWT() {
	QByteArray gByte(3 * g.size() * g[0].size(), 0);
	if (g.size()) {
		for (int i = 0; i < g.size(); i++)
			for (int j = 0; j < g[0].size(); j++) {
				gByte[0 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
				gByte[1 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
				gByte[2 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
			}
	}
	return gByte;
}

QByteArray JP2Encoder::GetBDWT() {
	QByteArray bByte(3 * b.size() * b[0].size(), 0);
	if (b.size()) {
		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < b[0].size(); j++) {
				bByte[0 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
				bByte[1 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
				bByte[2 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
			}
	}
	return bByte;
}

void JP2Encoder::run() {
	DWTProcessor dwtRProcessor(r);
	DWTProcessor dwtGProcessor(g);
	DWTProcessor dwtBProcessor(b);

	dwtRProcessor.start();
	dwtGProcessor.start();
	dwtBProcessor.start();

	dwtRProcessor.wait();
	dwtGProcessor.wait();
	dwtBProcessor.wait();

	r = dwtRProcessor.GetResultMatrix();
	g = dwtGProcessor.GetResultMatrix();
	b = dwtBProcessor.GetResultMatrix();
}