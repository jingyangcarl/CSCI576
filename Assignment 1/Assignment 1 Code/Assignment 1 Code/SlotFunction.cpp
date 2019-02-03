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
		letterBoxingSwitch = ui.horizontalSlider_letter_boxing_switch->value();
		seamCarvingSwitch = ui.horizontalSlider_seam_carving_switch->value();
		int x(0);

		// update frame
		for (int i = 0; i < height; i++) {
			int y(0);

			for (int j = 0; j < width; j++) {
				// the r, g, b are arranged in order of rrrr, gggg, bbbb

				// get rgb values
				int r = RGB[(3 * k + 0) * width * height + i * width + j];
				int g = RGB[(3 * k + 1) * width * height + i * width + j];
				int b = RGB[(3 * k + 2) * width * height + i * width + j];

				if (x < currentHeight && y < currentWidth)
					image.setPixel(y, x, qRgb(r, g, b));

				// width scale
				if ((j % 10) < widthScaler) y++;
			}
			// height scale
			if ((i % 10) < heightScaler) x++;
		}

		if (antiAliasingSwitch) {
			// low pass filter
			QImage desImage(currentWidth, currentHeight, QImage::Format_RGB32);
			AntiAliasingOperator aaOperator(image, desImage);
			aaOperator.start();

			while (aaOperator.isRunning()) {
				QCoreApplication::processEvents();
			}

			aaOperator.wait();
			image = desImage;
		}

		if (letterBoxingSwitch && heightScaler != widthScaler) {
			// non linear mapping
			QImage desImage = image;
			int srcHeight = image.height();
			int srcWidth = image.width();

			if (widthScaler < heightScaler) {
				int desHeight = srcWidth * height / width;
				int desX(srcHeight / 2 - desHeight / 2);

				for (int srcX = 0; srcX < srcHeight; srcX++) {
					int desY(0);
					for (int srcY = 0; srcY < srcWidth; srcY++) {
						int r = desImage.pixelColor(srcY, srcX).red();
						int g = desImage.pixelColor(srcY, srcX).green();
						int b = desImage.pixelColor(srcY, srcX).blue();

						if (desX < srcHeight / 2 + desHeight / 2)
							image.setPixel(desY, desX, qRgb(r, g, b));

						if ((srcY % widthScaler) < widthScaler) desY++;
					}
					if ((srcX % heightScaler) < widthScaler) desX++;
				}
			}
			else {
				int desWidth = srcHeight * width / height;
				int desX(0);

				for (int srcX = 0; srcX < srcHeight; srcX++) {
					int desY(srcWidth / 2 - desWidth / 2);
					for (int srcY = 0; srcY < srcWidth; srcY++) {
						int r = desImage.pixelColor(srcY, srcX).red();
						int g = desImage.pixelColor(srcY, srcX).green();
						int b = desImage.pixelColor(srcY, srcX).blue();

						if (desY < srcWidth / 2 + srcWidth / 2)
							image.setPixel(desY, desX, qRgb(r, g, b));

						if ((srcY % widthScaler) < heightScaler) desY++;
					}
					if ((srcX % heightScaler) < heightScaler) desX++;
				}
			}
		}

		if (seamCarvingSwitch) {
			QImage desImage(currentWidth, currentHeight, QImage::Format_RGB32);
			SeamCarvingOperator scOperator(image, desImage);
			scOperator.start();

			while (scOperator.isRunning()) {
				QCoreApplication::processEvents();
			}

			scOperator.wait();
			image = desImage;
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