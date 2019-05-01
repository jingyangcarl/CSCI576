#include <QtCore/QCoreApplication>
#include <qaudiobuffer.h>
#include <qaudiooutput.h>
#include <qaudioformat.h>
#include <qbuffer.h>
#include <qdebug.h>
#include <qfile.h>
#include <qiodevice.h>
#include "wavfile.h"
#include <iostream>

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	// read WAV file
	WavFile wavFile;
	QString filePath = "D:/CSCI576/Final Project/Data/dataset/Ads/Starbucks_Ad_15s.wav";
	//QString filePath = "D:/CSCI576/Final Project/Data/dataset/Videos/data_test1.wav";
	wavFile.setFileName(filePath);

	// open WAV file
	if (wavFile.exists() == false)
		return a.exec();
	wavFile.open(filePath);

	// Read samples
	QAudioBuffer wavBuffer(wavFile.readAll(), wavFile.fileFormat());
	qDebug() << wavFile.fileFormat();
	const qint16 *data16 = wavBuffer.constData<qint16>();
	const char *data8 = wavBuffer.constData<char>();

	//QByteArray wavArray(wavBuffer.constData<char>(), wavBuffer.byteCount());
	QByteArray wavArray, tempWav;
	//wavArray = wavArray.fromRawData((char *)wavBuffer.data(), wavBuffer.byteCount());
	wavArray = QByteArray((char *)wavBuffer.data(), wavBuffer.byteCount());
	//QBuffer buffer(&wavArray);
	QBuffer buffer(&tempWav);
	buffer.open(QIODevice::ReadOnly);

	// test on buffer
	// "data_test1.wav" has 14394335 samples
	qDebug() << "QAudioBuffer Byte Count:" << wavBuffer.byteCount();
	// output: 28788670
	qDebug() << "QAudioBuffer Sample Count:" << wavBuffer.sampleCount();
	// output: 14394335
	qDebug() << "QAudioBuffer Frame Count:" << wavBuffer.frameCount();
	// output: 14394335

	//QAudioOutput *audio = new QAudioOutput(wavFile.fileFormat(), 0);
	QAudioOutput *audio = new QAudioOutput(QAudioDeviceInfo::defaultInputDevice(), wavFile.fileFormat());
	qDebug() << audio->error();
	qDebug() << audio->state();
	audio->start(&buffer);

	return a.exec();
}