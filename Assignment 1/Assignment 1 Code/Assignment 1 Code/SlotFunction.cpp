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

	QImage image(width*widthScaler / 10, height*heightScaler / 10, QImage::Format_RGB32);
	for (int k = 0; k < frames; k++) {
		// get current scaler
		widthScaler = ui.horizontalSlider_width_scale->value();
		heightScaler = ui.horizontalSlider_height_scale->value();
		fpsScaler = ui.horizontalSlider_fps_scale->value();
		int y(0);

		// update frame
		for (int i = 0; i < height; i++) {
			int x(0);

			// height scale
			if (i % (10 / heightScaler) != 0) continue;
			for (int j = 0; j < width; j++) {
				// the r, g, b are arranged in order of rrrr, gggg, bbbb

				// width scale
				if ((j % (10 / widthScaler)) != 0) continue;
				// get rgb values
				int r = RGB[(3 * k + 0) * width * height + i * width + j];
				int g = RGB[(3 * k + 1) * width * height + i * width + j];
				int b = RGB[(3 * k + 2) * width * height + i * width + j];

				// set rgb values to pixel
				image.setPixel(x, y, qRgb(r, g, b));
				x++;
			}
			y++;
		}
		ui.label_image->setPixmap(QPixmap::fromImage(image));

		// update frame infor
		ui.label_status->setText("Playing");
		frameIndex++;
		ui.label_frame_index_val->setText(QString::number(frameIndex));

		// update
		QCoreApplication::processEvents();

		Sleep(-20 * (fpsScaler / 20) + 20);
	}

	// update frame info
	ui.label_status->setText("Playing Finished");
}

void Assignment1Code::setWidthScalerVal(int val) {
	ui.label_width_scale_val->setText(QString::number(val / 10.0));
}

void Assignment1Code::setHeightScalerVal(int val) {
	ui.label_height_scale_val->setText(QString::number(val / 10.0));
}

void Assignment1Code::setFPSScalerVal(int val) {
	ui.label_fps_scale_val->setText(QString::number(val / 20.0));
}