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

vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    if (!root)  return ret;

    vector<TreeNode *> prev, cur;
    prev.push_back(root);

    while (!prev.empty()) {
        ret.push_back(prev[prev.size() - 1]->val);
        for (int i = 0; i < prev.size(); i++) {
            TreeNode *tmp = prev[i];
            if (tmp->left)  cur.push_back(tmp->left);
            if (tmp->right) cur.push_back(tmp->right);
        }
        prev = cur;
        cur.clear();
    }

    return ret;
}

int main() {

}
