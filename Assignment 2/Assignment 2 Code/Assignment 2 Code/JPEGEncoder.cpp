#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder(QByteArray & rgb, bool & encodeStatus) :
	rgb(rgb), encodeStatus(encodeStatus) {
	r = QVector<QVector<float>>(512, QVector<float>(512, 0));
	g = QVector<QVector<float>>(512, QVector<float>(512, 0));
	b = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			r[i][j] = (uchar)rgb[0 * 512 * 512 + i * 512 + j];
			g[i][j] = (uchar)rgb[1 * 512 * 512 + i * 512 + j];
			b[i][j] = (uchar)rgb[2 * 512 * 512 + i * 512 + j];
		}
	}
}

void JPEGEncoder::run() {
	// Convert RGB color space to YCrCb color space
	RGBToYCrCb();

	y = BlockDCT_512(y);

	PrintGrayScale(y);
}

/*
Description:
	This function is used to transform RGB color space to YCrCb color space
Input:
	@
Output:
	@
*/
void JPEGEncoder::RGBToYCrCb() {
	// convert rgb color space to ycbcr color space

	y = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cb = QVector<QVector<float>>(512, QVector<float>(512, 0));
	cr = QVector<QVector<float>>(512, QVector<float>(512, 0));

	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			y[i][j] = 0.2989*r[i][j] + 0.5866*g[i][j] + 0.1145*b[i][j];
			cb[i][j] = -0.1687*r[i][j] - 0.3313*g[i][j] + 0.5000*b[i][j];
			cr[i][j] = 0.5000*r[i][j] - 0.4184*g[i][j] - 0.0816*b[i][j];
		}
	}
}

/*
Description:
	This function is used to shrink the matrix to half of its size
Input:
	@QVector<QVector<float>> matrix: the given color matrix
Output:
	@QVector<QVector<float>> matrix: the matrix after shrinking
*/
QVector<QVector<float>> JPEGEncoder::Shrink_2(QVector<QVector<float>>& matrix) {
	QVector<QVector<float>> shrinkMatrix(matrix.size() / 2, QVector<float>(matrix[0].size() / 2));

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (!(i % 2) && !(j % 2))
				shrinkMatrix[i / 2][j / 2] = matrix[i][2];
		}
	}

	return shrinkMatrix;
}

/*
Description:
	This function is used to transform any given matrix from time domain to frequency domain
Input:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix, which needed to be transform to frequency domain
Output:
	@ QVector<QVector<float>> matrix: an 2D M (rows) by N (cols) matrix representing frequency infomation
*/
QVector<QVector<float>> JPEGEncoder::DiscreteCosinTransform(QVector<QVector<float>> const & matrix) {
	QVector<QVector<float>> matrixDCT = matrix;
	int m = matrix.size();
	int n = matrix[0].size();

	for (int u = 0; u < m; u++) {
		for (int v = 0; v < n; v++) {
			matrixDCT[u][v] = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					matrixDCT[u][v] += matrix[i][j] * cos(M_PI / ((float)m)*(i + 1.0 / 2.0) * u) * cos(M_PI / ((float)n)*(j + 1.0 / 2.0) * v);
				}
			}
			matrixDCT[u][v] *= sqrt(2.0 / m) * sqrt(2.0 / n) * (u == 0 ? 1.0 / sqrt(2) : 1) * (v == 0 ? 1.0 / sqrt(2) : 1);
		}
	}

	return matrixDCT;
}

/*
Description:
	This function is used to quantize the given 8 by 8 matrix using the quantization table,
	where the quantization table is:
	quantizationTable = {
		{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{14, 17, 22, 29, 51, 87, 80, 62},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{72, 92, 96, 98, 112, 100, 103, 99}
	}
Input:
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix that needs to be quantized
Output:
	@ QVector<QVector<float>> matrix: an 8 by 8 matrix after quantization
*/
QVector<QVector<float>> JPEGEncoder::DCTQuantization_8(QVector<QVector<float>> const & matrix) {
	int const quantizationTable[8][8] = {
		{16, 11, 10, 16, 24, 40, 51, 61},
		{12, 12, 14, 19, 26, 58, 60, 55},
		{14, 13, 16, 24, 40, 57, 69, 56},
		{14, 17, 22, 29, 51, 87, 80, 62},
		{18, 22, 37, 56, 68, 109, 103, 77},
		{24, 35, 55, 64, 81, 104, 113, 92},
		{49, 64, 78, 87, 103, 121, 120, 101},
		{72, 92, 96, 98, 112, 100, 103, 99}
	};

	if (matrix.size() == 8 && matrix[0].size() == 8) {
		QVector<QVector<float>> quantizedMatrix(8, QVector<float>(8, 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				quantizedMatrix[i][j] = round(matrix[i][j] / (float)quantizationTable[i][j]);
			}
		}
		return quantizedMatrix;
	}
	else return QVector<QVector<float>>();
}

/*
Description:
	This function is used to divide an given 512 by 512 matrix into several blocks of size 8 by 8.
	For each block, a DiscreteCosinTransform(DCT) is conducted to transform the block from time domain to frequency domain.
	Next, a quantization is performed on the block using the quantization table
Input:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix needed to be transformed
Output:
	@ QVector<QVector<float>> matrix: an 512 by 512 matrix after block DCT transformation and quantization
*/
QVector<QVector<float>> JPEGEncoder::BlockDCT_512(QVector<QVector<float>> const & matrix) {
	if (matrix.size() % 8 != 0) return QVector<QVector<float>>();
	else if (matrix[0].size() % 8 != 0) return QVector<QVector<float>>();
	else {
		QVector<QVector<float>> resultMatrix(matrix.size(), QVector<float>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size() / 8; i++) {
			for (int j = 0; j < matrix[0].size() / 8; j++) {
				QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						subMatrix[ii][jj] = matrix[i * 8 + ii][j * 8 + jj];
				subMatrix = DiscreteCosinTransform(subMatrix);
				subMatrix = DCTQuantization_8(subMatrix);
				for (int ii = 0; ii < 8; ii++)
					for (int jj = 0; jj < 8; jj++)
						resultMatrix[i * 8 + ii][j * 8 + jj] = subMatrix[ii][jj];
			}
		}
		return resultMatrix;
	}
}
/*
Description:
	This funtion is used to transform the given matrix to an array in zig-zag order
Input:
	@ QVector<QVector<float>> matrix: input matrix
Output:
	@ QVector<float> array: array holds entries in matrix in a zig-zag order
*/
QVector<float> JPEGEncoder::ZigZagSeries(QVector<QVector<float>> const & matrix) {
	QVector<float> zigzag;
	bool direction(false);
	if (matrix.size() == 0) return QVector<float>();
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
	return zigzag;
}

/*
Description:
	This function is used to encode given vocabularies with frequences
Input:
	@ QMap<QString, int> input: a map holds the vocabularies with frequences
		@ QString: vocabulary in a string form
		@ int: frequency for each vocabulary (the time that vocabulary appears)
	@ QMap<QString, QString> output: a map holds vocabularies with its binary huffmand code
		@ QString: vocabulary in a string form
		@ QString: huffman code for vocabulary
*/
QMap<QString, QString> JPEGEncoder::HuffmanEncode(QMap<QString, int> input) {
	// input contains "<2, 3>" with its frequency
	// output will transform frequency to its code in QString form

	struct BinaryTreeNode {
		QString content;
		int frequency;
		BinaryTreeNode * left;
		BinaryTreeNode * right;

		BinaryTreeNode(int frequency) {
			this->content = "";
			this->frequency = frequency;
			this->left = this->right = NULL;
		}
		BinaryTreeNode(QString content, int frequency) {
			this->content = content;
			this->frequency = frequency;
			this->left = this->right = NULL;
		}
		BinaryTreeNode(const BinaryTreeNode & node) {
			this->content = node.content;
			this->frequency = node.frequency;
			this->left = node.left;
			this->right = node.right;
		}
		constexpr bool operator< (const BinaryTreeNode & node) const {
			return frequency > node.frequency;
		}
	};

	// Build Huffman Tree
	std::priority_queue<BinaryTreeNode> minHeap;

	for (int i = 0; i < input.size(); i++) {
		QMap<QString, int>::iterator iter = input.begin() + i;
		BinaryTreeNode node(iter.key(), iter.value());
		minHeap.push(node);
	}

	while (minHeap.size() != 1) {
		BinaryTreeNode node_1(minHeap.top());
		minHeap.pop();
		BinaryTreeNode node_2(minHeap.top());
		minHeap.pop();
		BinaryTreeNode node(node_1.frequency + node_2.frequency);
		node.left = new BinaryTreeNode(node_1);
		node.right = new BinaryTreeNode(node_2);
		minHeap.push(node);
	}

	// Huffmand Encode
	struct Encode {
		static void HuffmanEncode(BinaryTreeNode *huffmanTree, QString code, QMap<QString, QString> & huffmanCode) {
			if (!huffmanTree->left && !huffmanTree->right) {
				huffmanCode.insert(huffmanTree->content, code);
			}
			else {
				HuffmanEncode(huffmanTree->left, code + '1', huffmanCode);
				HuffmanEncode(huffmanTree->right, code + '0', huffmanCode);
			}
		};
	};

	BinaryTreeNode * huffmanTree = new BinaryTreeNode(minHeap.top());
	QMap<QString, QString> huffmanCode;
	Encode::HuffmanEncode(huffmanTree, QString(), huffmanCode);

	return huffmanCode;
}

/*
Description:
	This function returns the Variable Length Integer code for given number, which is encoded in following patterns
	1 -> 1 | -1 -> 0
	2 -> 10 | -2 -> 01
	3 -> 11 | -3 -> 00
	4 -> 100 | -4 -> 011
Input:
	@ int number: a number in decimal form
Output:
	@ QString number: a number in binary form
*/
QString JPEGEncoder::VLIEncode(int number) {
	// given a number, transform the number to VLI code
	bool positive = (abs(number) == number);
	QString bits(QString::number(abs(number), 2));
	if (!positive) {
		for (int i = 0; i < bits.size(); i++)
			bits[i] = bits[i] == '0' ? '1' : '0';
	}
	return bits;
}

QString JPEGEncoder::EntropyEncode_512(QVector<QVector<float>> matrix) {
	// encode submatrix using Huffman and Runlength

	for (int i = 0; i < matrix.size() / 8; i++) {
		for (int j = 0; j < matrix[0].size() / 8; j++) {
		}
	}
	return QString();
}

/*
Description:
	Ourput the given matrix to main QT thread for display using rgb byte stream
Input:
	@ QVector<QVector<float>> matrix: an matrix need to be displayed
Output:
	@ void
*/
void JPEGEncoder::PrintGrayScale(QVector<QVector<float>> const & matrix) {
	// print gray scale image
	for (int i = 0; i < 512; i++) {
		for (int j = 0; j < 512; j++) {
			rgb[0 * 512 * 512 + i * 512 + j] = matrix[i][j];
			rgb[1 * 512 * 512 + i * 512 + j] = matrix[i][j];
			rgb[2 * 512 * 512 + i * 512 + j] = matrix[i][j];
		}
	}
}