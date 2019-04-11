#include <QtCore/QCoreApplication>
#include <qaudiobuffer.h>
#include <qfile.h>
#include "wavfile.h"
#include <qdebug.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	WavFile wavFile;
	QString filePath = "D:/576 Data/dataset/Videos/data_test1.wav";
	wavFile.setFileName(filePath);

	if (wavFile.exists() == false)
		return a.exec();
	wavFile.open(filePath);

	QAudioBuffer wavBuffer(wavFile.readAll(), wavFile.fileFormat());

	const quint16 *data = wavBuffer.constData<quint16>();

	return a.exec();
}
