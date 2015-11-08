#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode *root, string curPath, vector<string>& ret) {
    if (root->left == NULL && root->right == NULL) {
        ret.push_back(curPath);
        return;
    }

    if (root->left != NULL)
        dfs(root->left, curPath + "->" + to_string(root->left->val), ret);
    if (root->right != NULL)
        dfs(root->right, curPath + "->" + to_string(root->right->val), ret);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if (root != NULL)
        dfs(root, to_string(root->val), ret);
    return ret;
}

int main() {

}
