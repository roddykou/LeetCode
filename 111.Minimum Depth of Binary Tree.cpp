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

int dfs(TreeNode *root, const int height) {
    if (root->left == NULL && root->right == NULL) {
        return height;
    } else if (root->left == NULL) {
        return dfs(root->right, height + 1);
    } else if (root->right == NULL) {
        return dfs(root->left, height + 1);
    } else {
        return min(dfs(root->left, height + 1),
                   dfs(root->right, height + 1));
    }
}

int minDepth(TreeNode* root) {
    return root == NULL ? 0 : dfs(root, 1);
}

int main() {

}
