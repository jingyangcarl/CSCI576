#include "Testor.h"
#include "qvector.h"

void Testor::run() {

	QVector<QVector<float>> matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	QVector<float> zigzag;
	bool direction(false);
	for (int i = 0; i < matrix.size() + matrix[0].size() - 1; i++) {
		int j = i;
		while (j >= 0) {
			if (!direction && j < matrix.size() && (i - j) < matrix[0].size())
				zigzag.push_back(matrix[j][i - j]);
			if (direction && (i - j) < matrix.size() && j < matrix[0].size())
				zigzag.push_back(matrix[i - j][j]);
			j--;
		}
		direction = !direction;
	}

}
