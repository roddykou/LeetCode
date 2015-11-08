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

bool dfs(TreeNode *root, int& height) {
    if (root == NULL) {
        height = 0;
        return true;
    }

    int leftHeight, rightHeight;
    bool ret = dfs(root->left, leftHeight) &&
               dfs(root->right, rightHeight);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    } else {
        height = max(leftHeight, rightHeight) + 1;
        return ret;
    }
}

bool isBalanced(TreeNode* root) {
    int height = 0;
    return dfs(root, height);
}


int main() {

}
