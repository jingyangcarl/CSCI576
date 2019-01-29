#pragma once
#include <qthread.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qvector.h>

class FileLoader : public QThread {
public:
	//FileLoader(QString filePath, QVector<QVector<char>> &RGB, QVector<int> &fileDetail, bool &loadStatus);
	FileLoader(QString filePath, QByteArray &RGB, QVector<int> &fileDetail, bool &loadStatus);

	void setFilePath(QString filePath);
	QString getFilePath();

protected:
	void run();

private:
	QString filePath;
	//QVector<QVector<char>> &RGB;
	QByteArray &RGB;
	QVector<int> &fileDetail;
	bool &loadStatus;

	int load();
};