#include "AudioLoader.h"

AudioLoader::AudioLoader(QString filePath, QByteArray & wav) : 
	filePath(filePath), wav(wav) {
	startSampleIndex = 0;
}

AudioLoader::AudioLoader(QString filePath, QByteArray & wav, qint64 startSampleIndex) : 
	filePath(filePath), wav(wav), startSampleIndex(startSampleIndex) {
}

void AudioLoader::SetStartSampleIndex(qint64 startSampleIndex) {
	this->startSampleIndex = startSampleIndex;
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

		if (!file.open(filePath)) return;

		// Read samples
		file.seek(startSampleIndex);
		QAudioBuffer buffer(file.read(file.size() - startSampleIndex), file.fileFormat());
		//wav = QByteArray::fromRawData((char *)buffer.data(), buffer.byteCount());

		wav = QByteArray((char *)buffer.data(), buffer.byteCount());
		
		// set variables
		format = file.fileFormat();
		loadStatus = true;
	}
}
