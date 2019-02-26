#include "Testor.h"
#include "qvector.h"
#include "qbitarray.h"

void Testor::run() {

	int number = -10;
	QVector<QString> stringList;

	while (number != 10) {
		bool positive = (abs(number) == number);
		QString bits(QString::number(abs(number), 2));
		if (!positive) {
			for (int i = 0; i < bits.size(); i++)
				bits[i] = bits[i] == '0' ? '1' : '0';
		}
		stringList.append(bits);
		number++;
	}

	int a(0);
	a += number;
	return;
}
