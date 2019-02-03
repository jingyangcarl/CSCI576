#include "SeamCarvingOperator.h"

SeamCarvingOperator::SeamCarvingOperator(QImage & srcImage, QImage & desImage) :
	srcImage(srcImage), desImage(desImage) {
}

void SeamCarvingOperator::ToGrayScale() {
	// convert the original image to grayscale image
	grayImage = QVector<QVector<float>>(srcImage.height(), QVector<float>(srcImage.width(), 0));
	for (int i = 0; i < srcImage.height(); i++) {
		for (int j = 0; j < srcImage.width(); j++) {
			int r = srcImage.pixelColor(j, i).red();
			int g = srcImage.pixelColor(j, i).green();
			int b = srcImage.pixelColor(j, i).blue();
			grayImage[i][j] = qGray(r, g, b);
		}
	}
}

void SeamCarvingOperator::CalculateGradiant() {
	G = QVector<QVector<float>>(srcImage.height(), QVector<float>(srcImage.width(), 0));
	QVector<int> kernal_H = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	QVector<int> kernal_V = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	for (int i = 1; i < srcImage.height() - 1; i++) {
		for (int j = 1; j < srcImage.width() - 1; j++) {
			int val_H(0);
			int val_V(0);
			for (int ii = -1; ii < 2; ii++) {
				for (int jj = -1; jj < 2; jj++) {
					val_H += kernal_H[(ii + 1) * 3 + jj + 1] * grayImage[i + ii][j + jj];
					val_V += kernal_V[(ii + 1) * 3 + jj + 1] * grayImage[i + ii][j + jj];
				}
			}
			G[i][j] = abs(val_H / 9.0) + abs(val_V / 9.0);
		}
	}
}

void SeamCarvingOperator::OutputGrayScale() {
	for (int i = 0; i < srcImage.height(); i++) {
		for (int j = 0; j < srcImage.width(); j++) {
			desImage.setPixelColor(j, i, qRgb(grayImage[i][j], grayImage[i][j], grayImage[i][j]));
		}
	}
}

void SeamCarvingOperator::OutputGradiant() {
	for (int i = 0; i < srcImage.height(); i++) {
		for (int j = 0; j < srcImage.width(); j++) {
			desImage.setPixelColor(j, i, qRgb(G[i][j], G[i][j], G[i][j]));
		}
	}
}

void SeamCarvingOperator::run() {
	ToGrayScale();
	//OutputGrayScale();
	CalculateGradiant();
	OutputGradiant();
}
