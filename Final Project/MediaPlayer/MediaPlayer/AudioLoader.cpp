#include "AudioLoader.h"

AudioLoader::AudioLoader(QString filePath, QByteArray & wav) : 
	filePath(filePath), wav(wav) {
}

QAudioFormat AudioLoader::GetAudioFormat() {
	return format;
}

bool AudioLoader::GetLoadStatus() {
	return loadStatus;
}

void AudioLoader::run() {
	load();
}

void AudioLoader::load() {

	WavFile file;
	file.setFileName(filePath);
	QFileInfo fileInfo(file);

	if (!file.exists()) return;

	if (fileInfo.suffix() == "wav") {

		if (file.open(QIODevice::ReadOnly)) return;

		// Read samples
		QAudioBuffer buffer(file.readAll(), file.fileFormat());
		wav = wav.fromRawData((char *)buffer.data(), buffer.byteCount());
		
		// set variables
		format = file.fileFormat();
		loadStatus = true;
	}
}
