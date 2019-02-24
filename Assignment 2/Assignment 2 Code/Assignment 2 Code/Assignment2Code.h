#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include "ui_Assignment2Code.h"
#include "FileLoader.h"

class Assignment2Code : public QMainWindow {
	Q_OBJECT

public:
	Assignment2Code(QWidget *parent = Q_NULLPTR);


public slots:
	void PushButtonLoadFile();

private:
	Ui::Assignment2CodeClass ui;

	// private variable
	QString filePath;
	QByteArray rgb;
	bool loadStatus;
};
