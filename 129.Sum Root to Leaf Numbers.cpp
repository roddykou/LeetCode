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

void dfs(TreeNode *root, int& sum, int prev) {
    if (!root)  return;

    int cur = prev * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        sum += cur;
        return;
    }

    if (root->left != NULL)
        dfs(root->left, sum, cur);
    if (root->right != NULL)
        dfs(root->right, sum, cur);
}

int sumNumbers(TreeNode* root) {
    int sum = 0, prev = 0;
    dfs(root, sum, prev);
    return sum;
}

int main() {

}
