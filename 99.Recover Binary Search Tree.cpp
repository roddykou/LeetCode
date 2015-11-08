#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *pre = NULL, *left = NULL, *right = NULL;
void recoverTree(TreeNode* root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL) {
        if (cur->left) {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                check(cur);
                cur = cur->right;
            }
        } else {
            check(cur);
            cur = cur->right;

        }
    }
    swap(left->val, right->val);
}

void check(TreeNode *cur) {
    if (pre != NULL && pre->val > cur->val) {
        if (left == NULL) {
            left = pre;
            right = cur;
        } else {
            right = cur;
        }
    }
    pre = cur;
}
