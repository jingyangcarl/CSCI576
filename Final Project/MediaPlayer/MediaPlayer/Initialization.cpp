#include "MediaPlayer.h"

void MediaPlayer::ConnectionInitialization() {
	connect(ui.pushButton_load, SIGNAL(clicked), this, SLOT(PushButtonLoad()));
}