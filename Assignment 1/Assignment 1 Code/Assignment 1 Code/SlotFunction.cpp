#include "Assignment1Code.h"

void Assignment1Code::loadFile() {
	filePath = QFileDialog::getOpenFileName(this, tr("Select Image or Video File"), "./", tr("Video File(*.rgb)\n Image File(*.bmp)"));
	ui.textEdit->setText(filePath);

	// initialization
	RGB = QByteArray();;
	fileDetail = QVector<int>();
	loadStatus = false;

	// load file
	FileLoader fileLoader(filePath, RGB, fileDetail, loadStatus);
	fileLoader.start();

	// update UI
	int timer(0), change(40);
	while (fileLoader.isRunning()) {
		// Carl: update loading infor;
		if ((timer % (4 * change)) / change == 0)
			ui.label_status->setText("Loading.");
		else if ((timer % (4 * change)) / change == 1)
			ui.label_status->setText("Loading..");
		else if ((timer % (4 * change)) / change == 2)
			ui.label_status->setText("Loading...");
		else if ((timer % (4 * change)) / change == 3)
			ui.label_status->setText("Loading....");
		timer++;

		// Carl: call event process;
		QCoreApplication::processEvents();
	}

	// waite thread
	fileLoader.wait();

	// update infor
	if (!fileDetail.empty()) {
		ui.label_status->setText("Loading Finished");
		width = fileDetail[0];
		ui.label_width_val->setText(QString::number(width));
		height = fileDetail[1];
		ui.label_height_val->setText(QString::number(height));
		colorDepth = fileDetail[2];
		ui.label_color_depth_val->setText(QString::number(colorDepth));
		frames = fileDetail[3];
		ui.label_frames_val->setText(QString::number(frames));
		frameIndex = fileDetail[4];
		ui.label_frame_index_val->setText(QString::number(frameIndex));
		frameSize = fileDetail[5];
		ui.label_frame_size_val->setText(QString::number(frameSize));
		rChannelSize = fileDetail[6];
		ui.label_r_channel_size_val->setText(QString::number(rChannelSize));
		gChannelSize = fileDetail[7];
		ui.label_g_channel_size_val->setText(QString::number(gChannelSize));
		bChannelSize = fileDetail[8];
		ui.label_b_channel_size_val->setText(QString::number(bChannelSize));
	}
	else ui.label_status->setText("Loading Failed");

	// create the image
	QImage image(width, height, QImage::Format_RGB32);
	// QImage::Format_RGB16 - The image is stored using a 16-bit RGB format (5-6-5).
	// QImage::Format_RGB32 - The image is stored using a 32-bit RGB format (0xffRRGGBB).
	// QImage::Format_ARGB32 - The image is stored using a 32-bit ARGB format (0xAARRGGBB).
	// QImage::Format_RGB666 - The image is stored using a 24-bit RGB format (6-6-6). The unused most significant bits is always zero.
	// QImage::Format_RGB555 - The image is stored using a 16-bit RGB format (5-5-5). The unused most significant bit is always zero.
	// QImage::Format_RGB888 - The image is stored using a 24-bit RGB format (8-8-8).

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			image.setPixel(j, i, qRgb(RGB[i*width * 3 + 3 * j], RGB[i*width * 3 + 3 * j + 1], RGB[i*width * 3 + 3 * j + 2]));
			//image.setPixel(j, i, qRgb(channelR[i*width + j], channelG[i*width + j], channelB[i*width + j]));
		}
	}
	ui.label_image->setPixmap(QPixmap::fromImage(image));
}

void Assignment1Code::play() {
	// play video

	// intialize the frame index
	frameIndex = 0;

	// initialize the frame parameters
	int widthScaler = ui.horizontalSlider_width_scale->value();
	int heightScaler = ui.horizontalSlider_height_scale->value();
	int fpsScaler = ui.horizontalSlider_fps_scale->value();
	bool antiAliasingSwitch = ui.horizontalSlider_anti_aliasing_switch->value();
	bool letterBoxingSwitch = ui.horizontalSlider_letter_boxing_switch->value();
	bool seamCarvingSwitch = ui.horizontalSlider_seam_carving_switch->value();
	ui.horizontalSlider_width_scale->setDisabled(true);
	ui.horizontalSlider_height_scale->setDisabled(true);

	// set up a timer
	QElapsedTimer timer;

	// set current width and height
	int currentWidth = width * widthScaler / 10.0;
	int currentHeight = height * heightScaler / 10.0;
	QImage image(currentWidth, currentHeight, QImage::Format_RGB32);
	for (int k = 0; k < frames; k++) {
		// start a timer
		timer.start();

		// get current scaler
		fpsScaler = ui.horizontalSlider_fps_scale->value();
		antiAliasingSwitch = ui.horizontalSlider_anti_aliasing_switch->value();
		int x(0);

		// update frame
		for (int i = 0; i < height; i++) {
			int y(0);

			for (int j = 0; j < width; j++) {
				// the r, g, b are arranged in order of rrrr, gggg, bbbb

				// set rgb values to pixel
				//if (antiAliasingSwitch) {
				//	if (x >= 1 && x < currentHeight - 1 && y >= 1 && y < currentWidth - 1) {
				//		int r(0), g(0), b(0);
				//		for (int ii = -1; ii < 2; ii++) {
				//			for (int jj = -1; jj < 2; jj++) {
				//				r += RGB[(3 * k + 0) * width * height + (i + ii) * width + j + jj];
				//				g += RGB[(3 * k + 1) * width * height + (i + ii) * width + j + jj];
				//				b += RGB[(3 * k + 2) * width * height + (i + ii) * width + j + jj];
				//			}
				//		}
				//		if (x < currentHeight && y < currentWidth)
				//			image.setPixel(y, x, qRgb(r / 9, g / 9, b / 9));
				//	}
				//	else {
				//		int r = RGB[(3 * k + 0) * width * height + i * width + j];
				//		int g = RGB[(3 * k + 1) * width * height + i * width + j];
				//		int b = RGB[(3 * k + 2) * width * height + i * width + j];
				//		if (x < currentHeight && y < currentWidth)
				//			image.setPixel(y, x, qRgb(r, g, b));
				//	}
				//}
				{
					// get rgb values
					int r = RGB[(3 * k + 0) * width * height + i * width + j];
					int g = RGB[(3 * k + 1) * width * height + i * width + j];
					int b = RGB[(3 * k + 2) * width * height + i * width + j];
					if (x < currentHeight && y < currentWidth)
						image.setPixel(y, x, qRgb(r, g, b));
				}

				// width scale
				if ((j % 10) < widthScaler) y++;
			}
			// height scale
			if ((i % 10) < heightScaler) x++;
		}

		if (antiAliasingSwitch) {
			// los pass filter
			// where the kernal of the filter is defined as [1/9, 1/9, 1/9; 1/9, 1/9, 1/9; 1/9, 1/9, 1/9]
			currentHeight = image.height();
			currentWidth = image.width();
			for (int i = 1; i < currentHeight - 1; i++) {
				for (int j = 1; j < currentWidth - 1; j++) {
					// get rgb in the neighbors
					int r(0), g(0), b(0);
					for (int ii = -1; ii < 2; ii++) {
						for (int jj = -1; jj < 2; jj++) {
							r += image.pixelColor(j + jj, i + ii).red();
							g += image.pixelColor(j + jj, i + ii).green();
							b += image.pixelColor(j + jj, i + ii).blue();
						}
					}
					if (i < currentHeight && j < currentWidth)
						image.setPixel(j, i, qRgb(r / 9, g / 9, b / 9));
				}
			}
		}

		if (letterBoxingSwitch) {
		}

		if (seamCarvingSwitch) {
			// conver the image to gray image
			QVector<QVector<int>> image_gray(height, QVector<int>(width, 0));
			for (int i = 0; i < currentHeight; i++) {
				for (int j = 0; j < currentWidth; j++) {
					int r = image.pixelColor(j, i).red();
					int g = image.pixelColor(j, i).green();
					int b = image.pixelColor(j, i).blue();
					image_gray[i][j] = qGray(r, g, b);
					// see the grayscale image
					// image.setPixel(j, i, qRgb(image_gray[i][j], image_gray[i][j], image_gray[i][j]));
				}
			}

			// calculate energy matrix G
			QVector<QVector<float>> G(height, QVector<float>(width, 0));
			QVector<int> kernal_H = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
			QVector<int> kernal_V = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
			for (int i = 1; i < currentHeight - 1; i++) {
				for (int j = 1; j < currentWidth - 1; j++) {
					int val_H(0);
					int val_V(0);
					for (int ii = -1; ii < 2; ii++) {
						for (int jj = -1; jj < 2; jj++) {
							val_H += kernal_H[(ii + 1) * 3 + jj + 1] * image_gray[i][j];
							val_V += kernal_V[(ii + 1) * 3 + jj + 1] * image_gray[i][j];
						}
					}
					G[i][j] = abs(val_H / 9.0) + abs(val_V / 9.0);
					// see the energy matrix G
					image.setPixel(j, i, qRgb(G[i][j] / 2, G[i][j] / 2, G[i][j] / 2));
				}
			}

			// calculate energy matrix M, as well as flag matrix R
			QVector<QVector<float>> M(G);
			QVector<QVector<float>> R(height, QVector<float>(width, 0));

			for (int i = 1; i < G.size(); i++) {
				QVector<QVector<float>>::iterator currentG = G.begin() + i;
				QVector<QVector<float>>::iterator currentM = M.begin() + i;
				QVector<QVector<float>>::iterator currentR = R.begin() + i;
				QVector<QVector<float>>::iterator previousM = M.begin() + i - 1;

				// for the first row
				if ((*previousM)[0] <= (*previousM)[1]) {
					(*currentM)[0] = (*currentG)[0] + (*previousM)[0];
					(*currentR)[0] = 1;
				}
				else {
					(*currentM)[0] = (*currentG)[0] + (*previousM)[1];
					(*currentR)[0] = 2;
				}

				// for the middle rows
				for (int j = 1; j < G[0].size() - 1; j++) {
					float k[3];
					k[0] = (*previousM)[j - 1];
					k[1] = (*previousM)[j];
					k[2] = (*previousM)[j + 1];

					int index(0);
					if (k[1] < k[0])
						index = 1;
					if (k[2] < k[index])
						index = 2;
					(*currentM)[j] = (*currentG)[j] + (*previousM)[j - 1 + index];
					(*currentR)[j] = index;
				}

				// for the last row
				if ((*previousM)[G[0].size() - 1] <= (*previousM)[G[0].size() - 2]) {
					(*currentM)[G[0].size() - 1] = (*currentG)[G[0].size() - 1] + (*previousM)[G[0].size() - 1];
					(*currentR)[G[0].size() - 1] = 1;
				}
				else {
					(*currentM)[G[0].size() - 1] = (*currentG)[G[0].size() - 1] + (*previousM)[G[0].size() - 2];
					(*currentR)[G[0].size() - 1] = 0;
				}
			}

			// find the line with minimum energy
			QVector<float> minEnergyLine(height);
			int index = 0;
			QVector<QVector<float>>::iterator lastM = M.end() - 1;
			for (int i = 0; i < M.size(); i++) {
				if ((*lastM)[i] < (*lastM)[index])
					index = i;
			}

			minEnergyLine[minEnergyLine.size() - 1] = index;
			int tmpIndex = index;

			for (int i = minEnergyLine.size() - 1; i > 0; i--) {
				QVector<QVector<float>>::iterator currentR = R.begin() + i;
				int temp = (*currentR)[tmpIndex];

				if (temp == 0)
					tmpIndex = tmpIndex - 1;
				else if (temp == 2)
					tmpIndex = tmpIndex + 1;

				minEnergyLine[i - 1] = tmpIndex;
			}

			// show the line

			// delete the line

		}

		ui.label_image->setPixmap(QPixmap::fromImage(image));

		// update frame infor
		ui.label_status->setText("Playing");
		frameIndex++;
		ui.label_frame_index_val->setText(QString::number(frameIndex));

		// update QT events
		QCoreApplication::processEvents();

		// update frame rate
		Sleep(-100 * (fpsScaler / 100.0) + 100);
		ui.label_frame_rate_val->setText(QString::number(1000.0 / (timer.elapsed())));
	}

	// update frame info
	ui.label_status->setText("Playing Finished");

	// update widgets
	ui.horizontalSlider_width_scale->setEnabled(true);
	ui.horizontalSlider_height_scale->setEnabled(true);
}

void Assignment1Code::setWidthScalerVal(int val) {
	ui.label_width_scale_val->setText(QString::number(val / 10.0));
}

void Assignment1Code::setHeightScalerVal(int val) {
	ui.label_height_scale_val->setText(QString::number(val / 10.0));
}

void Assignment1Code::setFPSScalerVal(int val) {
	ui.label_fps_scale_val->setText(QString::number(val / 100.0));
}

void Assignment1Code::setAntiAliasingVal(int val) {
	ui.label_anti_aliasing_switch_val->setText(val ? "ON" : "OFF");
}

void Assignment1Code::setLetterBoxingVal(int val) {
	ui.label_letter_boxing_switch_val->setText(val ? "ON" : "OFF");
}

void Assignment1Code::setSeamCarvingVal(int val) {
	ui.label_seam_carving_switch_val->setText(val ? "ON" : "OFF");
}