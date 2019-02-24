#pragma once
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qvector.h>

class FileLoader : public QThread {
public:
	FileLoader(QString &filePath, QByteArray &rgb, bool &loadStatus);

protected:
	void run();

private:
	// Variable References
	QString &filePath;
	QByteArray &rgb;
	bool &loadStatus;

	// Function
	void load();
};