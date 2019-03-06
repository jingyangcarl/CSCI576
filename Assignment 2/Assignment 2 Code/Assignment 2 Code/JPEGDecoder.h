#pragma once
#include <qthread.h>
#include <qvector.h>
#include <qmath.h>
#include "IDCTProcessor.h"

class JPEGDecoder : public QThread {
public:
	JPEGDecoder(QVector<float> & rgb);
	JPEGDecoder(QVector<float> & rgb, int gear);
	void SetGear(int gear);
	QByteArray RGBSerielization();

private:
	// Variable References
	const QVector<float> & rgb;

	// Paramete
	int gear;

	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	QVector<QVector<float>> ZigZagDeserielization(QVector<float> zigzag, int gear);
	void RGBZigZagDeserielization(int gear);

protected:
	void run();
};