#include "MediaPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MediaPlayer w;
	w.show();
	return a.exec();
}
