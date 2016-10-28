#include <iostream>
#include <string>

using namespace std;

struct Interval {
	int start, end;
	Interval *left, *right;
	Interval (int s, int e) : start(s), end(e), left(nullptr), right(nullptr) {}
};

class IntervalTree {
public:
	void Insert(int s, int e) {
		if (s > e)	return;
		if (_root == nullptr)	_root = new Interval(s, e);
		else Insert(s, e, _root);
	}

	Interval *Search(int i) {
		return nullptr;
	}

	void Print() {
		cout << Print(_root) << endl;
	}

	IntervalTree() { _root = nullptr; }

private:
	Interval *_root;

	string Print(Interval *root) {
		if (root == nullptr)	return "null";
		string ret = "(" + to_string(root->start) + ", " + to_string(root->end) + "), " + 
			   		 Print(root->left) + ", "  + Print(root->right);
		return ret;
	}

	void Insert(int s, int e, Interval *root) {
		if (root == nullptr) {
			return;
		} else if (s >= root->start && e <= root->end) {
			return;
		} else if (e < root->start) {
			if (root->left == nullptr)
				root->left = new Interval(s, e);
			else
				Insert(s, e, root->left);
		} else if (s > root->end) {
			if (root->right == nullptr)
				root->right = new Interval(s, e);
			else
				Insert(s, e, root->right);
		} else {
			if (s < root->start)
				updateTreeFromStart(s, root, root->left);
			if (e > root->end)
				updateTreeFromEnd(e, root, root->right);
			root->start = min(root->start, s);
			root->end = max(root->end, e);
		}
	}

	void updateTreeFromStart(int& s, Interval *previous, Interval *current) {
		if (previous == nullptr || current == nullptr) {
			return;
		} else if (s < current->start) {
			updateTreeFromStart(s, current, current->left);
			if (current == previous->left)
				previous->left = current->left;
			else if (current == previous->right)
				previous->right = current->left;
		} else if (s >= current->start && s <= current->end) {
			s = current->start;
			if (current == previous->left)
				previous->left = current->left;
			else if (current == previous->right)
				previous->right = current->left;
		} else if (s > current->end) {
			updateTreeFromStart(s, current, current->right);
		}
	}

	void updateTreeFromEnd(int& e, Interval *previous, Interval *current) {
		if (previous == nullptr || current == nullptr) {
			return;
		} else if (e > current->end) {
			updateTreeFromEnd(e, current, current->right);
			if (current == previous->left)
				previous->left = current->right;
			else if (current == previous->right)
				previous->right = current->right;
		} else if (e >= current->start && e <= current->end) {
			e = current->end;
			if (current == previous->left)
				previous->left = current->right;
			else if (current == previous->right)
				previous->right = current->right;
		} else if (e < current->start) {
			updateTreeFromEnd(e, current, current->left);
		}
	}
};

int main() {
	IntervalTree *tree = new IntervalTree();
	tree->Insert(20, 22);
	tree->Insert(10, 12);
	tree->Insert(4, 6);
	tree->Insert(15, 17);
	tree->Insert(1, 3);
	tree->Insert(7, 9);
	tree->Insert(13, 14);
	tree->Insert(18, 19);

	tree->Insert(8,21);
	tree->Print();
	delete tree;
}