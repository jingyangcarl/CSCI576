#pragma once
#include <qthread.h>
#include <qvector.h>

class JP2Encoder : public QThread {
public:
	JP2Encoder(QByteArray &rgb);
private:
	// Variable References
	QByteArray & rgb;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

protected:
	void run();
};
