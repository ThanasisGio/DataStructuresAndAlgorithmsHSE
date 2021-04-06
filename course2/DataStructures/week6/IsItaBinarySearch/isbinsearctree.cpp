#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

#define ll long long

#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647



struct Node {

	int key;
	int left;
	int right;

	Node() : key(0), left(-1), right(-1) {}
	Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}

};



bool IsBinarySearchTree(const vector<Node>& tree, const int &index, int min, int max) {

	if (index == -1)
		return true;

	if (tree[index].key < min || tree[index].key > max)
		return false;

	return

		IsBinarySearchTree(tree, tree[index].left, min, tree[index].key) &&
		IsBinarySearchTree(tree, tree[index].right, tree[index].key, max);

}

bool isBinarySearchTree(const vector<Node>& tree) {

	if (tree.size() == 0)
		return true;

	return IsBinarySearchTree(tree, 0, INT_MIN, INT_MAX);

}

int main() {

	int nodes;
	cin >> nodes;

	vector<Node> tree;

	for (int i = 0; i < nodes; ++i) {

		int key, left, right;
		cin >> key >> left >> right;

		tree.push_back(Node(key, left, right));

	}


	if (isBinarySearchTree(tree))
		cout << "CORRECT" << endl;

	else
		cout << "INCORRECT" << endl;


	return 0;
}
