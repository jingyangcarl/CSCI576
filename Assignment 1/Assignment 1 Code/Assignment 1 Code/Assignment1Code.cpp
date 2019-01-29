#include "Assignment1Code.h"

Assignment1Code::Assignment1Code(QWidget *parent)
	: QMainWindow(parent) {
	ui.setupUi(this);

	layoutInitialization();
	widgetInitialization();
	connectionInitialization();

	//frameReader();
	//frameSeparator();
}

void Assignment1Code::frameReader() {
	//QFile file("./video_prison_960_540.rgb");
	QFile file("./video_prison_960_540_10.rgb");
	// For 'video_prison_960_540.rgb', there are 155520000 bytes in the file
	// where each frame takes up 960*540*3 = 1555200 bytes
	// hence, there are 155520000/1555200 = 100 frames without head in each image.
	// read each bitmap one by one
	if (!file.exists())
		ui.textEdit->setText("Current file doesn't exist");
	else if (!file.open(QIODevice::ReadOnly))
		ui.textEdit->setText("Cannot open the current file ");

	// initialization
	int width(960);
	int height(540);
	int size = 3 * width * height;

	QVector<char> channelR;
	QVector<char> channelG;
	QVector<char> channelB;
	int frame(0);
	int byteCounter(0);
	char currentByte;

	// read file byte by byte
	while (!file.atEnd()) {
		file.read(&currentByte, sizeof(char));
		if (byteCounter >= frame * size && byteCounter < (frame + 1)*size) {
			switch (byteCounter % 3) {
			case 0: channelR.push_back(currentByte); break;
			case 1: channelG.push_back(currentByte); break;
			case 2: channelB.push_back(currentByte); break;
			}
		}
		byteCounter++;
	}
	ui.textEdit->setText(QString::number(byteCounter));

	QImage image(width, height, QImage::Format_RGB32);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			image.setPixel(j, i, qRgb(channelR[i*width + j], channelG[i*width + j], channelB[i*width + j]));
		}
	}

	ui.label_image->setPixmap(QPixmap::fromImage(image));
}

void Assignment1Code::frameSeparator() {
	// initialization
	QFile iFile("./video_prison_960_540.rgb");
	iFile.open(QIODevice::ReadOnly);
	QByteArray byteArray = iFile.readAll();
	int totalFrames(100*9);
	int width(960/3);
	int height(540/3);
	int frameSize(width * height * 3);

	for (int frame = 0; frame < totalFrames; frame++) {
		QString path = "./Separator_320_180/video_prison_960_540_" + QString::number(frame) + ".rgb";
		QFile oFile(path);
		oFile.open(QIODevice::WriteOnly);
		oFile.write(byteArray.mid(frame*frameSize, frameSize));
		oFile.close();
	}
	iFile.close();
}