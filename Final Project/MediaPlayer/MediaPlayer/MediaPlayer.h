#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayer.h"

class MediaPlayer : public QMainWindow
{
	Q_OBJECT

public:
	MediaPlayer(QWidget *parent = Q_NULLPTR);

	/*-----------------Initialization.cpp---------------------*/
	void ConnectionInitialization();
	/*-----------------SlotFunction.cpp---------------------*/
public slots:
	void PushButtonLoad();

private:
	Ui::MediaPlayerClass ui;

	// Private Variables
	QString filePath;
	QByteArray irgb;
	QByteArray orgb;
};
