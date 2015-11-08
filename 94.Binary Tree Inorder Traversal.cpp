#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;

	if (!root)
		return ret;

	TreeNode *curr;
	stack<TreeNode *> s;
	s.push(root);

	/* We don't need a prev pointer
	 * The trick is how do we avoid infinite loop.
     * (number of NULLs = number of nodes + 1)
	 * So, we push NULL onto stack this time !!! */
	while (!s.empty()) {
		curr = s.top();
		if (curr) {
			s.push(curr->left);
		} else {
			s.pop();

			/* making sure s.top != NULL */
			if (!s.empty()) {
				curr = s.top();
				ret.push_back(curr->val);
				s.pop();
				s.push(curr->right);
			}
		}
	}
	return ret;
}

vector<int> inorderMorrisTraversal(TreeNode *root) {
    vector<int> ret;
    TreeNode *cur = root, *prev = NULL;

    while (cur != NULL) {
        if (cur->left == NULL) {
            ret.push_back(cur->val);
            cur = cur->right;
        } else {
            prev = cur->left;
            /* IMPORTANT */
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else if (prev->right == cur) {
                prev->right = NULL;
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return ret;
}

int main() {

}
