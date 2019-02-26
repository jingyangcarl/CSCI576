#pragma once
#include <qthread.h>

class Testor : public QThread {
protected:
	void run();
};