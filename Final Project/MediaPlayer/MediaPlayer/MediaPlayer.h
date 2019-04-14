#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MediaPlayer.h"

class MediaPlayer : public QMainWindow
{
	Q_OBJECT

public:
	MediaPlayer(QWidget *parent = Q_NULLPTR);

private:
	Ui::MediaPlayerClass ui;
};
