#include <QtCore/QCoreApplication>
#include <qaudiobuffer.h>
#include <qfile.h>
#include "wavfile.h"
#include <qdebug.h>

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	WavFile wavFile;
	QString filePath = "D:/576 Data/dataset/Videos/data_test1.wav";
	wavFile.setFileName(filePath);

	if (wavFile.exists() == false)
		return a.exec();
	wavFile.open(filePath);

	QAudioBuffer wavBuffer(wavFile.readAll(), wavFile.fileFormat());

	const qint16 *data = wavBuffer.constData<qint16>();
	//const short *data = wavBuffer.constData<short>();
	//const float *data = wavBuffer.constData<float>();

	// "data_test1.wav" has 14394335 samples
	qDebug() << "QAudioBuffer Byte Count:" << wavBuffer.byteCount();
	// output: 28788670
	qDebug() << "QAudioBuffer Sample Count:" << wavBuffer.sampleCount();
	// output: 14394335
	qDebug() << "QAudioBuffer Frame Count:" << wavBuffer.frameCount();
	// output: 14394335

	for (int i = 0; i < 10; i++)
		qDebug() << (double)data[927 + i];

	return a.exec();
}