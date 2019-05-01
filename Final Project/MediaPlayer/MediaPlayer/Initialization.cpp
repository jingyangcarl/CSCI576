#include "MediaPlayer.h"

void MediaPlayer::ConnectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked()), this, SLOT(PushButtonLoad()));
	connect(ui.pushButton_play, SIGNAL(clicked()), this, SLOT(PushButtonPlay()));
	connect(ui.pushButton_stop, SIGNAL(clicked()), this, SLOT(PushButtonStop()));
	connect(ui.pushButton_replay, SIGNAL(clicked()), this, SLOT(PushButtonReplay()));

}