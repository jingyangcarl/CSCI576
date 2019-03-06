#pragma once
#include <qthread.h>
#include <qvector.h>
#include "IDWTProcessor.h"

class JP2Decoder : public QThread {
public:
	JP2Decoder(QVector<float> & rgb, int gear);

private:
	// Variable References
	const QVector<float> & rgb;

	// Parameter
	int gear;


	// RGB Color Spaces
	QVector<QVector<float>> r;
	QVector<QVector<float>> g;
	QVector<QVector<float>> b;

	// Function
	
protected:
	void run();
};