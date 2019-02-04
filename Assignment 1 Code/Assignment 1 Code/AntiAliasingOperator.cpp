#include "AntiAliasingOperator.h"

AntiAliasingOperator::AntiAliasingOperator(QImage & srcImage, QImage & desImage) :
	srcImage(srcImage), desImage(desImage) {
}

void AntiAliasingOperator::LowPassConvolution() {
	// the kernal of the filter is defined as[1 / 9, 1 / 9, 1 / 9; 1 / 9, 1 / 9, 1 / 9; 1 / 9, 1 / 9, 1 / 9]
	for (int i = 1; i < srcImage.height() - 1; i++) {
		for (int j = 1; j < srcImage.width() - 1; j++) {
			int r(0), g(0), b(0);
			for (int ii = -1; ii < 2; ii++) {
				for (int jj = -1; jj < 2; jj++) {
					r += srcImage.pixelColor(j + jj, i + ii).red();
					g += srcImage.pixelColor(j + jj, i + ii).green();
					b += srcImage.pixelColor(j + jj, i + ii).blue();
				}
			}
			if (i < srcImage.height() && j < srcImage.width())
				desImage.setPixel(j, i, qRgb(r / 9, g / 9, b / 9));
		}
	}
}

void AntiAliasingOperator::run() {
	LowPassConvolution();
}
