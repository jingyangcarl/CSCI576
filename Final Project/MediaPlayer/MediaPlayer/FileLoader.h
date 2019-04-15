#pragma once
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>

class FileLoader : public QThread {
public:
	FileLoader(QString &filePath, QByteArray &rgb);

protected:
	void run();

private:
	// Variable References
	QString &filePath;
	QByteArray &rgb;

	// Function
	void load();
};