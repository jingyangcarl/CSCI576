#include "JPEGEncoder.h"

JPEGEncoder::JPEGEncoder(QByteArray & rgb) :
	rgb(rgb) {
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

QByteArray JPEGEncoder::GetYDCT() {
	QByteArray yByte(3 * y.size() * y[0].size(), 0);
	if (y.size()) {
		for (int i = 0; i < y.size(); i++)
			for (int j = 0; j < y[0].size(); j++) {
				yByte[0 * y.size() * y[0].size() + i * y.size() + j] = y[i][j];
				yByte[1 * y.size() * y[0].size() + i * y.size() + j] = y[i][j];
				yByte[2 * y.size() * y[0].size() + i * y.size() + j] = y[i][j];
			}
	}
	return yByte;
}

QByteArray JPEGEncoder::GetCrDCT() {
	QByteArray crByte(3 * cr.size() * cr[0].size(), 0);
	if (cr.size()) {
		for (int i = 0; i < cr.size(); i++)
			for (int j = 0; j < cr[0].size(); j++) {
				crByte[0 * cr.size() * cr[0].size() + i * cr.size() + j] = cr[i][j];
				crByte[1 * cr.size() * cr[0].size() + i * cr.size() + j] = cr[i][j];
				crByte[2 * cr.size() * cr[0].size() + i * cr.size() + j] = cr[i][j];
			}
	}
	return crByte;
}

QByteArray JPEGEncoder::GetCbDCT() {
	QByteArray cbByte(3 * cb.size() * cb[0].size(), 0);
	if (cb.size()) {
		for (int i = 0; i < cb.size(); i++)
			for (int j = 0; j < cb[0].size(); j++) {
				cbByte[0 * cb.size() * cb[0].size() + i * cb.size() + j] = cb[i][j];
				cbByte[1 * cb.size() * cb[0].size() + i * cb.size() + j] = cb[i][j];
				cbByte[2 * cb.size() * cb[0].size() + i * cb.size() + j] = cb[i][j];
			}
	}
	return cbByte;
}

QByteArray JPEGEncoder::GetRDCT() {
	QByteArray rByte(3 * r.size() * r[0].size(), 0);
	if (r.size()) {
		for (int i = 0; i < r.size(); i++)
			for (int j = 0; j < r[0].size(); j++) {
				rByte[0 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
				rByte[1 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
				rByte[2 * r.size() * r[0].size() + i * r.size() + j] = r[i][j];
			}
	}
	return rByte;
}

QByteArray JPEGEncoder::GetGDCT() {
	QByteArray gByte(3 * g.size() * g[0].size(), 0);
	if (g.size()) {
		for (int i = 0; i < g.size(); i++)
			for (int j = 0; j < g[0].size(); j++) {
				gByte[0 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
				gByte[1 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
				gByte[2 * g.size() * g[0].size() + i * g.size() + j] = g[i][j];
			}
	}
	return gByte;
}

QByteArray JPEGEncoder::GetBDCT() {
	QByteArray bByte(3 * b.size() * b[0].size(), 0);
	if (b.size()) {
		for (int i = 0; i < b.size(); i++)
			for (int j = 0; j < b[0].size(); j++) {
				bByte[0 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
				bByte[1 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
				bByte[2 * b.size() * b[0].size() + i * b.size() + j] = b[i][j];
			}
	}
	return bByte;
}

/*
Description:
	This function is used to serielize a zigzag order of y channel, cb channel, as well as cr channel
Input:
	@
Output:
	@ QVector<float> ycrcb: serielized ycrcb
*/
QVector<float> JPEGEncoder::YCrCbZigZagSerielization() {
	QVector<float> ycrcb;

	// y channel
	for (int i = 0; i < y.size() / 8; i++) {
		for (int j = 0; j < y[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for(int ii = 0; ii < 8; ii++)
				for(int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = y[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				ycrcb.push_back(subArray[i]);
		}
	}
	// cr channel
	for (int i = 0; i < cr.size() / 8; i++) {
		for (int j = 0; j < cr[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for (int ii = 0; ii < 8; ii++)
				for (int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = cr[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				ycrcb.push_back(subArray[i]);
		}
	}
	// cb channel
	for (int i = 0; i < cb.size() / 8; i++) {
		for (int j = 0; j < cb[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for (int ii = 0; ii < 8; ii++)
				for (int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = cb[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				ycrcb.push_back(subArray[i]);
		}
	}

	return ycrcb;
}

/*
Description:
	This function is used to serielize a zigzag order of r channel, g channel, as well as b channel
Input:
	@
Output:
	@ QVector<float> rgb: serielized ycrcb
*/
QVector<float> JPEGEncoder::RGBZigZagSerielization() {
	QVector<float> rgb;

	// r channel
	for (int i = 0; i < r.size() / 8; i++) {
		for (int j = 0; j < r[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for (int ii = 0; ii < 8; ii++)
				for (int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = r[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				rgb.push_back(subArray[i]);
		}
	}
	// g channel
	for (int i = 0; i < g.size() / 8; i++) {
		for (int j = 0; j < g[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for (int ii = 0; ii < 8; ii++)
				for (int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = g[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				rgb.push_back(subArray[i]);
		}
	}
	// b channel
	for (int i = 0; i < b.size() / 8; i++) {
		for (int j = 0; j < b[0].size() / 8; j++) {
			QVector<QVector<float>> subMatrix(8, QVector<float>(8, 0));
			for (int ii = 0; ii < 8; ii++)
				for (int jj = 0; jj < 8; jj++)
					subMatrix[ii][jj] = b[i * 8 + ii][j * 8 + jj];
			QVector<float> subArray = ZigZagSeries(subMatrix);
			for (int i = 0; i < subArray.size(); i++)
				rgb.push_back(subArray[i]);
		}
	}

	return rgb;
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
			/*y[i][j] = 0.29900*r[i][j] + 0.58700*g[i][j] + 0.11400*b[i][j];
			cb[i][j] = -0.16874*r[i][j] - 0.33126*g[i][j] + 0.50000*b[i][j];
			cr[i][j] = 0.50000*r[i][j] - 0.41869*g[i][j] - 0.08131*b[i][j];*/
			y[i][j] = 0.257 * r[i][j] + 0.564 * g[i][j] + 0.098 * b[i][j] + 16;
			cb[i][j] = -0.148 * r[i][j] - 0.291 * g[i][j] + 0.439 * b[i][j] + 128;
			cr[i][j] = 0.439 * r[i][j] - 0.368 * g[i][j] - 0.071 * b[i][j] + 128;
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
				shrinkMatrix[i / 2][j / 2] = matrix[i][j];
		}
	}

	return shrinkMatrix;
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

void JPEGEncoder::run() {
	// Convert RGB color space to YCrCb color space
	RGBToYCrCb();

	// Using 4:2:0 mode
	cr = Shrink_2(cr);
	cb = Shrink_2(cb);

	// Conduct DCT
	DCTProcessor dctYProcessor(y);
	DCTProcessor dctCrProcessor(cr);
	DCTProcessor dctCbProcessor(cb);
	DCTProcessor dctRProcessor(r);
	DCTProcessor dctGProcessor(g);
	DCTProcessor dctBProcessor(b);

	dctYProcessor.start();
	dctCrProcessor.start();
	dctCbProcessor.start();
	dctRProcessor.start();
	dctGProcessor.start();
	dctBProcessor.start();

	dctYProcessor.wait();
	dctCrProcessor.wait();
	dctCbProcessor.wait();
	dctRProcessor.wait();
	dctGProcessor.wait();
	dctBProcessor.wait();

	y = dctYProcessor.GetResultMatrix();
	cr = dctCrProcessor.GetResultMatrix();
	cb = dctCbProcessor.GetResultMatrix();
	r = dctRProcessor.GetResultMatrix();
	g = dctGProcessor.GetResultMatrix();
	b = dctBProcessor.GetResultMatrix();
}