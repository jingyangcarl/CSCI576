#include "Testor.h"
#include "qvector.h"
#include <queue>
#include "qmap.h"
#include "qstack.h"

void Testor::run() {
	//Shrink_2Test();
	//Expand_2Test();
	SquareBlockDCTIDCTTest();
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
		{226, 226, 223, 223},
		{226, 226, 223, 223},
		{226, 226, 223, 223},
		{226, 226, 223, 223}
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