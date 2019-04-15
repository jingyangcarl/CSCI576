#include "MediaPlayer.h"
#include <qfiledialog.h>

void MediaPlayer::PushButtonLoad() {

	// Initialization
	filePath = QFileDialog::getOpenFileName(this, tr("Please Select File"), "./Resources", tr("RGB File(*.rgb)\n"));
	irgb = QByteArray();
	


}