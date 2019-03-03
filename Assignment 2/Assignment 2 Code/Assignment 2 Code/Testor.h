#pragma once
#include <qthread.h>
#include <qmath.h>

class Testor : public QThread {
protected:
	void run();
	void HuffmanEncode();
	void Shrink_2Test();
	void Expand_2Test();
	void SquareBlockDCTIDCTTest();
};