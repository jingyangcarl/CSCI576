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

void SeamCarvingOperator::CalculateEnergy() {
	E = G;
	R = QVector<QVector<float>>(srcImage.height(), QVector<float>(srcImage.width(), 0));

	for (int i = 1; i < G.size(); i++) {
		// for the first column
		if (E[i - 1][0] <= E[i - 1][1]) {
			E[i][0] = G[i][0] + E[i - 1][0];
			R[i][0] = 1;
		}
		else {
			E[i][0] = G[i][0] + E[i - 1][1];
			R[i][0] = 2;
		}

		// for the middle columns
		for (int j = 1; j < G[0].size() - 1; j++) {
			float k[3];
			k[0] = E[i - 1][j - 1];
			k[1] = E[i - 1][j];
			k[2] = E[i - 1][j + 1];

			int index = 0;
			if (k[1] < k[0]) index = 1;
			if (k[2] < k[index]) index = 2;
			E[i][j] = G[i][j] + E[i - 1][j - 1 + index];
			R[i][j] = index;
		}

		// for the last column
		if (E[i - 1][G[0].size() - 1] <= E[i - 1][G[0].size() - 2]) {
			E[i - 1][G[0].size() - 1] = G[i][G[0].size() - 1] + E[i - 1][G[0].size() - 1];
			R[i][G[0].size() - 1] = 1;
		}
		else {
			E[i - 1][G[0].size() - 1] = G[i][G[0].size() - 1] + E[i - 1][G[0].size() - 2];
			R[i][G[0].size() - 1] = 0;
		}
	}
}

void SeamCarvingOperator::CalculateMinEnergyLine() {
	minEnergyLine = QVector<float>(srcImage.height());
	int index;
	for (int i = 1; i < E[0].size(); i++) {
		if (E[E.size() - 1][i] < E[E.size() - 1][index])
			index = i;
	}

	minEnergyLine[minEnergyLine.size() - 1] = index;
	int tmpIndex = index;

	for (int i = minEnergyLine.size() - 1; i > 0; i--) {
		int temp = R[i][tmpIndex];

		if (temp == 0)
			tmpIndex = tmpIndex - 1;
		else if (temp == 2)
			tmpIndex = tmpIndex + 1;

		minEnergyLine[i - 1] = tmpIndex;
	}
}

void SeamCarvingOperator::DeleteMinEnergyLine() {
	desImage = QImage(srcImage.width() - 1, srcImage.height(), QImage::Format_RGB32);
	for (int i = 0; i < desImage.height(); i++) {
		int k = minEnergyLine[i];
		for (int j = 0; j < k; j++) {
			QColor color = srcImage.pixelColor(j, i);
			desImage.setPixel(j, i, qRgb(color.red(), color.green(), color.blue()));
		}
		for (int j = k; j < desImage.width() - 1; j++) {
			QColor color = srcImage.pixelColor(j + 1, i);
			desImage.setPixel(j, i, qRgb(color.red(), color.green(), color.blue()));
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

void SeamCarvingOperator::OutputEnergy() {
	for (int i = 0; i < srcImage.height(); i++) {
		for (int j = 0; j < srcImage.width(); j++) {
			desImage.setPixelColor(j, i, qRgb(E[i][j] / 4, E[i][j] / 4, E[i][j] / 4));
		}
	}
}

void SeamCarvingOperator::OutputFlag() {
	for (int i = 0; i < srcImage.height(); i++) {
		for (int j = 0; j < srcImage.width(); j++) {
			desImage.setPixelColor(j, i, qRgb(R[i][j] * 20, R[i][j] * 20, R[i][j] * 20));
		}
	}
}

void SeamCarvingOperator::OutputMinEnergyLine() {
	desImage = srcImage;
	for (int i = 0; i < srcImage.height(); i++) {
		int k = minEnergyLine[i];
		desImage.setPixelColor(k, i, qRgb(0, 0, 0));
	}
}

void SeamCarvingOperator::run() {
	ToGrayScale();
	//OutputGrayScale();
	CalculateGradiant();
	//OutputGradiant();
	CalculateEnergy();
	OutputEnergy();
	//OutputFlag();
	CalculateMinEnergyLine();
	//OutputMinEnergyLine();
	//DeleteMinEnergyLine();
}