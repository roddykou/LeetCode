#include <iostream>

using namespace std;

struct Interval {
	int start, end;
	Interval *left, *right;
	Interval(int s, int e) : start (s), end (e), left (nullptr), right (nullptr) {}
};

class BinarySearchIntervalTree {
public:
	void Insert(int start, int end) {
		if (this->root == nullptr)
			root = new Interval(start, end);
		else
			Insert(start, end, this->root); 
	}

	bool Search(int val) {
		return true;
	}

	void Print() {
		Print(this->root);
		cout << endl;
	}

private:
	Interval *root = nullptr;

	int findNewEndAndUpdateTree(Interval *p, Interval *c, int newEnd) {
		if (p == nullptr) {
			cout << "fuck root is nullptr" << endl;
			return -1;
		}

		if (c == nullptr)
			return newEnd;

		if (newEnd < c->start)
			return findNewEndAndUpdateTree(c, c->left, newEnd);
		else {		// swallow the current node and everything on its left
			if (p->left == c) {
				p->left = c->right;
				return newEnd <= c->end ? c->end : findNewEndAndUpdateTree(p, p->left, newEnd);
			} else if (p->right == c) {
				p->right = c->right;
				return newEnd <= c->end ? c->end : findNewEndAndUpdateTree(p, p->right, newEnd);
			} else {
				cout << "fuck lost track of tree while finding new end value" << endl;
				return -1;
			}
		}
	}

	int findNewStartAndUpdateTree(Interval *p, Interval *c, int newStart) {
		if (p == nullptr) {
			cout << "fuck root is nullptr" << endl;
			return -1;
		}

		if (c == nullptr)
			return newStart;

		if (newStart > c->end)
			return findNewStartAndUpdateTree(c, c->right, newStart);
		else {		// swallow the current node and everything on its right
			if (p->left == c) {
				p->left = c->left;
				return newStart >= c->start ? c->start : findNewStartAndUpdateTree(p, p->left, newStart);
			} else if (p->right == c) {
				p->right = c->left;
				return newStart >= c->start ? c->start : findNewStartAndUpdateTree(p, p->right, newStart);
			} else {
				cout << "fuck lost track of tree while finding new start value" << endl;
				return -1;
			}
		}
	}

	void Insert(int start, int end, Interval *root) {
		if (root == nullptr)	cout << "fuck root is nullptr" << endl;

		if (start >= root->start && end <= root->end)
			return;
		else if (end < root->start) {
			if (root->left == nullptr)
				root->left = new Interval(start, end);
			else
				Insert(start, end, root->left);
		} else if (start > root->end) {
			if (root->right == nullptr)
				root->right = new Interval(start, end);
			else
				Insert(start, end, root->right);
		} else {
			root->start = findNewStartAndUpdateTree(root, root->left, start);
			root->end = findNewEndAndUpdateTree(root, root->right, end);
		}
	}

	void Print(Interval *root) {
		if (root == nullptr)	return;
		Print(root->left);
		cout << "(" << root->start << ", " << root->end << "), ";
		Print(root->right);
 	}
};

int main() {
	BinarySearchIntervalTree tree;
	tree.Insert(30, 35);
	tree.Insert(20, 22);
	tree.Insert(10, 13);
	tree.Insert(27, 28);
	tree.Insert(24, 26);
	tree.Insert(50, 55);
	tree.Insert(70, 80);
	tree.Insert(56, 59);
	tree.Insert(60, 65);
	tree.Print();

	tree.Insert(29, 62);
	tree.Print();
}