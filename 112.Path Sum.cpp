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

bool dfs(TreeNode *root, const int sum, const int prev) {
    const int cur = prev + root->val;
    if (root->left == NULL && root->right == NULL)
        return cur == sum;
    else if (root->left == NULL)
        return dfs(root->right, sum, cur);
    else if (root->right == NULL)
        return dfs(root->left, sum, cur);
    else
        return dfs(root->right, sum, cur) || dfs(root->left, sum, cur);
}

bool hasPathSum(TreeNode* root, int sum) {
    return root != NULL && dfs(root, sum, 0);
}

int main() {

}
