#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right, *random;
	TreeNode(int v) : val (v), left(nullptr), right(nullptr), random(nullptr) {}
};

void printTree(TreeNode *root) {
	if (root != nullptr) {
		printTree(root->left);
		cout << endl << root->val << " ";
		if (root->random != nullptr)
			cout << "random: " << root->random->val << " ";
		printTree(root->right);
	}
}

TreeNode *cloneTree(TreeNode *root, unordered_map<TreeNode *, TreeNode *>& map) {
	TreeNode *ret = nullptr;
	if (root != nullptr) {
		if (map[root] == nullptr) {
			ret = new TreeNode(root->val);
			map[root] = ret;
		} else {
			ret = map[root];
		}

		if (root->random != nullptr) {
			if (map[root->random] == nullptr) {
				ret->random = new TreeNode(root->random->val);
				map[root->random] = ret->random;
			} else {
				ret->random = root->random;
			}
		}
		ret->left = cloneTree(root->left, map);
		ret->right = cloneTree(root->right, map);
	}
	return ret;
}

int main() {
	TreeNode one (1);
	TreeNode two (2);
	TreeNode three (3);
	TreeNode four (4);
	TreeNode five (5);
	TreeNode six (6);

	three.left = &one;
	three.right = &two;
	two.left = &four;
	two.right = &five;
	five.right = &six;

	one.random = &five;
	two.random = &one;
	// three.random = &four;
	four.random = &four;
	five.random = &six;
	six.random = &three;

	printTree(&three);
	cout << endl;
	unordered_map<TreeNode *, TreeNode *> map;
	printTree(cloneTree(&three, map));
}