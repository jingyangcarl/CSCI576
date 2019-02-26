#include "Testor.h"
#include "qvector.h"
#include "qbitarray.h"
#include <queue>
#include "qmap.h"
#include "qpair.h"

void Testor::run() {

	// using min heap to implement haffman code

	struct Compare {
		bool operator() (QPair<QString, float> node1, QPair<QString, float> node2) {
			return node1.second > node2.second;
		}
	};

	struct BinaryTreeNode {
		QString content;
		float frequency;
		BinaryTreeNode * left;
		BinaryTreeNode * right;
		BinaryTreeNode(QString content, float frequency) {
			this->content = content;
			this->frequency = frequency;
			this->left = NULL;
			this->right = NULL;
		}
	};

	QMap<QString, float> input;
	input.insert("0,0", 1);
	input.insert("0,1", 3);
	input.insert("1,2", 1);
	input.insert("2,1", 1);
	input.insert("2", 1);



	std::priority_queue<QPair<QString, float>, QVector<QPair<QString, float>>, Compare> minHeap;

	minHeap.push(QPair<QString, int>("10", 10));
	minHeap.push(QPair<QString, int>("20", 20));
	minHeap.push(QPair<QString, int>("30", 30));
	minHeap.push(QPair<QString, int>("5", 5));
	minHeap.push(QPair<QString, int>("15", 15));

	QVector<QPair<QString, int>> result;
	result.append(minHeap.top());
	minHeap.pop();
	result.append(minHeap.top());
	minHeap.pop();
	result.append(minHeap.top());
	minHeap.pop();
	result.append(minHeap.top());
	minHeap.pop();
	result.append(minHeap.top());
	minHeap.pop();




	result;
}
