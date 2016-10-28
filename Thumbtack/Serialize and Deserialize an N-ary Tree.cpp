#include <iostream>
#include <vector>

using namespace std;

/*
       A
     / | \ 
    B  C  D
   / \     \
  E   F     G

*/

struct TreeNode {
	char value;
	vector<TreeNode *> children;
	TreeNode(char v) : value (v) {}
};

string serialize(TreeNode *root) {
	if (root == nullptr)	return "";
	
	string ret (1, root->value);
	if (!root->children.empty())
		for (TreeNode *child : root->children)
			ret += serialize(child);

	ret += '#';
	return ret;
}

// A B E # F # # C # D G # # #
TreeNode *deserialize(const string& str, int& idx) {
	if (idx >= str.length() || str[idx] == '#') {
		idx++;
		return nullptr;
	}

	TreeNode *ret = new TreeNode(str[idx++]);
	while (true) {
		TreeNode *child = deserialize(str, idx);
		if (child == nullptr)
			break;
		else
			ret->children.push_back(child);
	}
	return ret;
}

int main() {
	TreeNode *A = new TreeNode('A');
	TreeNode *B = new TreeNode('B');
	TreeNode *C = new TreeNode('C');
	TreeNode *D = new TreeNode('D');
	TreeNode *E = new TreeNode('E');
	TreeNode *F = new TreeNode('F');
	TreeNode *G = new TreeNode('G');

	A->children.push_back(B);
	A->children.push_back(C);
	A->children.push_back(D);
	B->children.push_back(E);
	B->children.push_back(F);
	D->children.push_back(G);

	string ret = serialize(A);
	cout << ret << endl;

	int idx = 0;
	cout << serialize(deserialize(ret, idx)) << endl;
}