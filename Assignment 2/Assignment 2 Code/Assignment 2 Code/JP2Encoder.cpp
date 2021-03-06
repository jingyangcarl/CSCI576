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

/*
Description:
	This function is used to serielize a zigzag order of r channel, g channel, as well as b channel
Input:
	@
Output:
	@ QVector<float> rgb: serielized ycrcb
*/
QVector<float> JP2Encoder::RGBZigZagSerielization() {
	QVector<float> rgb;

	QVector<float> rArray = ZigZagSeries(r);
	QVector<float> gArray = ZigZagSeries(g);
	QVector<float> bArray = ZigZagSeries(b);

	for (int i = 0; i < rArray.size(); i++)
		rgb.append(rArray[i]);
	for (int i = 0; i < gArray.size(); i++)
		rgb.append(gArray[i]);
	for (int i = 0; i < bArray.size(); i++)
		rgb.append(bArray[i]);

	return rgb;
}

/*
Description:
	This funtion is used to transform the given matrix to an array in zig-zag order
Input:
	@ QVector<QVector<float>> matrix: input matrix
Output:
	@ QVector<float> array: array holds entries in matrix in a zig-zag order
*/
QVector<float> JP2Encoder::ZigZagSeries(QVector<QVector<float>> const & matrix) {
	QVector<float> zigzag;
	bool direction(false);
	if (matrix.size() == 0) return QVector<float>();
	for (int i = 0; i < matrix.size() + matrix[0].size() - 1; i++) {
		int j = i;
		while (j >= 0) {
			if (!direction && j < matrix.size() && (i - j) < matrix[0].size())
				zigzag.push_back(matrix[j][i - j]);
			if (direction && (i - j) < matrix.size() && j < matrix[0].size())
				zigzag.push_back(matrix[i - j][j]);
			j--;
		}
		direction = !direction;
	}
	return zigzag;
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