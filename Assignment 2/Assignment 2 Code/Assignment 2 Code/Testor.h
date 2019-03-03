#pragma once
#include <qthread.h>
#include <qmath.h>
#include <qbytearray.h>

class Testor : public QThread {
protected:
	void run();
	void HuffmanEncode();
	void Shrink_2Test();
	void Expand_2Test();
	void SquareBlockDCTIDCTTest();
	QByteArray ZigZagSeries(QVector<QVector<float>> const & matrix);
	QVector<QVector<float>> ZigZagDeseries(QByteArray const & zigzag);
};