#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int dfs(TreeNode *root, int& ret) {
    if (root == NULL)   return 0;
    int left = dfs(root->left, ret);
    int right = dfs(root->right, ret);
    ret = max(ret, root->val + left + right);
    return max(0, root->val + max(left, right));
}

int maxPathSum(TreeNode* root) {
    if (root == NULL)   return 0;
    int ret = INT_MIN;
    dfs(root, ret);
    return ret;
}

int main() {

}
