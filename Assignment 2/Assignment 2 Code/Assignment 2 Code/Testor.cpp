#include "Testor.h"
#include "qvector.h"
#include <queue>
#include "qmap.h"
#include "qstack.h"
#include "DCTProcessor.h"
#include "IDCTProcessor.h"

void Testor::run() {
	//Shrink_2Test();
	//Expand_2Test();
	//SquareBlockDCTIDCTTest();

	/*QVector<QVector<float>> matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9 }
	};
	QByteArray zigzag;

	zigzag = ZigZagSeries(matrix);
	matrix = ZigZagDeseries(zigzag);*/

	DCTIDCTProcessorTest();
}

void Testor::HuffmanEncode() {
	QMap<QString, float> input;
	input.insert("1", 5);
	input.insert("2", 7);
	input.insert("3", 10);
	input.insert("4", 15);
	input.insert("5", 20);
	input.insert("6", 45);

	// using min heap to implement haffman code

	struct BinaryTreeNode {
		QString content;
		float frequency;
		BinaryTreeNode * left;
		BinaryTreeNode * right;

		BinaryTreeNode(float frequency) {
			this->content = "";
			this->frequency = frequency;
			this->left = this->right = NULL;
		}
		BinaryTreeNode(QString content, float frequency) {
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

	std::priority_queue<BinaryTreeNode> minHeap;

	for (int i = 0; i < input.size(); i++) {
		QMap<QString, float>::iterator iter = input.begin() + i;
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

	BinaryTreeNode * huffmanTree = new BinaryTreeNode(minHeap.top());
	QMap<QString, QString> huffmanCode;

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

	Encode::HuffmanEncode(huffmanTree, QString(), huffmanCode);
}

void Testor::Shrink_2Test() {
	QVector<QVector<float>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 0, 1, 2},
		{3, 4, 5, 6}
	};

	QVector<QVector<float>> shrinkMatrix(matrix.size() / 2, QVector<float>(matrix[0].size() / 2));

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (!(i % 2) && !(j % 2))
				shrinkMatrix[i / 2][j / 2] = matrix[i][j];
		}
	}
}

void Testor::Expand_2Test() {
	QVector<QVector<float>> matrix = {
		{1, 3},
		{9, 1},
	};

	QVector<QVector<float>> expandMatrix(matrix.size() * 2, QVector<float>(matrix[0].size() * 2));

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			expandMatrix[2 * i][2 * j] = matrix[i][j];
			expandMatrix[2 * i + 1][2 * j] = matrix[i][j];
			expandMatrix[2 * i][2 * j + 1] = matrix[i][j];
			expandMatrix[2 * i + 1][2 * j + 1] = matrix[i][j];
		}
	}
}

void Testor::SquareBlockDCTIDCTTest() {
	QVector<QVector<float>> matrix = {
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{227, 227, 227, 222, 226, 228, 226, 230, 225, 228, 227, 225, 225, 223, 225, 225},
		{228, 228, 225, 224, 225, 229, 229, 229, 227, 227, 227, 228, 228, 224, 226, 224},
		{223, 223, 226, 221, 227, 225, 226, 228, 226, 224, 224, 225, 225, 226, 223, 225},
		{225, 225, 224, 224, 225, 224, 229, 225, 226, 225, 227, 226, 223, 225, 227, 227},
		{223, 223, 224, 222, 227, 225, 224, 227, 228, 223, 225, 224, 224, 224, 224, 230},
		{224, 224, 222, 222, 225, 230, 226, 225, 226, 225, 226, 228, 225, 224, 226, 226},
		{223, 223, 224, 226, 228, 227, 226, 224, 225, 225, 225, 226, 225, 227, 227, 227},
		{227, 227, 225, 227, 227, 228, 224, 224, 224, 224, 225, 226, 228, 226, 226, 226},
		{228, 228, 225, 226, 225, 226, 229, 226, 228, 225, 226, 226, 225, 226, 226, 225},
		{228, 228, 226, 223, 229, 224, 227, 227, 225, 221, 228, 226, 229, 225, 228, 225},
		{228, 228, 227, 226, 227, 225, 226, 228, 223, 223, 226, 226, 225, 224, 226, 225}
	};

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

	QVector<QVector<float>> inverseMatrixDCT = matrixDCT;
	m = matrixDCT.size();
	n = matrixDCT[0].size();

	for (int u = 0; u < m; u++) {
		for (int v = 0; v < n; v++) {
			inverseMatrixDCT[u][v] = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					float alpha = (i == 0 ? 1.0 / sqrt(m) : sqrt(2.0 / m)) * (j == 0 ? 1.0 / sqrt(n) : sqrt(2.0 / n));
					inverseMatrixDCT[u][v] += alpha * matrixDCT[i][j] * cos(M_PI / ((float)m)*(u + 1.0 / 2.0) * i) * cos(M_PI / ((float)n)*(v + 1.0 / 2.0) * j);
				}
			}
		}
	}
}

QByteArray Testor::ZigZagSeries(QVector<QVector<float>> const & matrix) {
	QByteArray zigzag;
	bool direction(false);
	if (matrix.size() == 0) return QByteArray();
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

QVector<QVector<float>> Testor::ZigZagDeseries(QByteArray const & zigzag) {
	if (zigzag.size() == 0) return QVector<QVector<float>>();
	QVector<QVector<float>> matrix(sqrt(zigzag.size()), QVector<float>(sqrt(zigzag.size()), 0));
	QByteArray::const_iterator iter = zigzag.begin();
	bool direction(false);
	for (int i = 0; i < 2 * sqrt(zigzag.size()) - 1; i++) {
		int j = i;
		while (j >= 0) {
			if (direction && (i - j) < matrix.size() && j < matrix.size())
				matrix[i - j][j] = *iter++;
			if (!direction && j < matrix.size() && (i - j) < matrix.size())
				matrix[j][i - j] = *iter++;
			j--;
		}
		direction = !direction;
	}
	return matrix;
}

void Testor::DCTIDCTProcessorTest() {


	QVector<QVector<float>> matrix = {
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{226, 226, 223, 223, 226, 226, 228, 227, 227, 225, 228, 225, 223, 226, 223, 221},
		{227, 227, 227, 222, 226, 228, 226, 230, 225, 228, 227, 225, 225, 223, 225, 225},
		{228, 228, 225, 224, 225, 229, 229, 229, 227, 227, 227, 228, 228, 224, 226, 224},
		{223, 223, 226, 221, 227, 225, 226, 228, 226, 224, 224, 225, 225, 226, 223, 225},
		{225, 225, 224, 224, 225, 224, 229, 225, 226, 225, 227, 226, 223, 225, 227, 227},
		{223, 223, 224, 222, 227, 225, 224, 227, 228, 223, 225, 224, 224, 224, 224, 230},
		{224, 224, 222, 222, 225, 230, 226, 225, 226, 225, 226, 228, 225, 224, 226, 226},
		{223, 223, 224, 226, 228, 227, 226, 224, 225, 225, 225, 226, 225, 227, 227, 227},
		{227, 227, 225, 227, 227, 228, 224, 224, 224, 224, 225, 226, 228, 226, 226, 226},
		{228, 228, 225, 226, 225, 226, 229, 226, 228, 225, 226, 226, 225, 226, 226, 225},
		{228, 228, 226, 223, 229, 224, 227, 227, 225, 221, 228, 226, 229, 225, 228, 225},
		{228, 228, 227, 226, 227, 225, 226, 228, 223, 223, 226, 226, 225, 224, 226, 225}
	};
	QVector<QVector<float>> resultMatrix;

	DCTProcessor dct(matrix);
	dct.start();
	dct.wait();
	resultMatrix = dct.GetResultMatrix();

	IDCTProcessor idct(resultMatrix);
	idct.start();
	idct.wait();
	resultMatrix = idct.GetResultMatrix();

	int count(0);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (abs(matrix[i][j] - resultMatrix[i][j]) > 0.01) count++;
		}
	}
}
