#include <QtCore/QCoreApplication>
#include <qaudiobuffer.h>
#include <qdebug.h>
#include <qfile.h>
#include "wavfile.h"
#include <iostream>

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	// read WAV file
	WavFile wavFile;
	QString filePath = "D:/576 Data/dataset2/Videos/data_test2.wav";
	wavFile.setFileName(filePath);

	// open WAV file
	if (wavFile.exists() == false)
		return a.exec();
	wavFile.open(filePath);

	// Read samples
	QAudioBuffer wavBuffer(wavFile.readAll(), wavFile.fileFormat());
	const qint16 *data = wavBuffer.constData<qint16>();

	// test on buffer
	// "data_test1.wav" has 14394335 samples
	qDebug() << "QAudioBuffer Byte Count:" << wavBuffer.byteCount();
	// output: 28788670
	qDebug() << "QAudioBuffer Sample Count:" << wavBuffer.sampleCount();
	// output: 14394335
	qDebug() << "QAudioBuffer Frame Count:" << wavBuffer.frameCount();
	// output: 14394335

	// cut audio
	int winLen = 200;
	QVector<int> subAudiosIndex;
	int lastCut = 0;
	for (int i = 0; i < wavBuffer.sampleCount() / winLen; i++) {
		int quantiSum = 0;
		for (int j = 0; j < winLen; j++)
			quantiSum += abs(data[i*winLen + j]);
		if (quantiSum / winLen < 20) {
			subAudiosIndex.append(i);
		}
	}

	QVector<int>::iterator iter;
	if(subAudiosIndex.size() <= 1)
		return a.exec();
	for (iter = subAudiosIndex.begin(); iter != subAudiosIndex.end(); iter++) {
		std::cout << (*iter) << '\t' << (*iter) / (48000.0 / winLen) << std::endl;
	}

	return a.exec();
}