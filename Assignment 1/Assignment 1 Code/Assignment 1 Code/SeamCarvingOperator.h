#pragma once
#include <qthread.h>
#include <qimage.h>

class SeamCarvingOperator : public QThread {
public:
	SeamCarvingOperator(QImage &srcImage, QImage &desImage);

	// seam carving operations
	void ToGrayScale();
	void CalculateGradiant();
	void CalculateEnergy();
	void CalculateMinEnergyLine();
	void DeleteMinEnergyLine();

	// output
	void OutputGrayScale();
	void OutputGradiant();
	void OutputEnergy();
	void OutputFlag();
	void OutputMinEnergyLine();

protected:
	void run();

private:
	QImage &srcImage;
	QImage &desImage;
	// grayscale image
	QVector<QVector<float>> grayImage;
	// gradiant matrix
	QVector<QVector<float>> G;
	// energy matrix
	QVector<QVector<float>> E;
	// flag matrix
	QVector<QVector<float>> R;
	// line index
	QVector<float> minEnergyLine;
};