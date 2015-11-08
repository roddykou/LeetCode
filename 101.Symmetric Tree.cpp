#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool dfs(TreeNode *left, TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;
    } else if (left == NULL || right == NULL) {
        return false;
    } else if (left->val == right->val) {
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    } else {
        return false;
    }
}

bool isSymmetric(TreeNode* root) {
    return root == NULL || dfs(root->left, root->right);
}

bool isSymmetricIter(TreeNode* root) {
    if (!root)  return true;

    TreeNode *left = NULL, *right = NULL;
    queue<TreeNode *> leftQ, rightQ;
    leftQ.push(root->left), rightQ.push(root->right);

    while (!leftQ.empty() && !rightQ.empty()) {
        left = leftQ.front(), right = rightQ.front();
        leftQ.pop(), rightQ.pop();
        if (left == NULL && right == NULL) {
            continue;
        } else if (left == NULL || right == NULL) {
            return false;
        } else if (left->val != right->val) {
            return false;
        } else {
            leftQ.push(left->left), leftQ.push(left->right);
            rightQ.push(right->right), rightQ.push(right->left);
        }
    }

    return leftQ.empty() && rightQ.empty();
}

int main() {

}
