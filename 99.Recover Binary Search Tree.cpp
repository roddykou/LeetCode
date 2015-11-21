#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *pre = NULL, *leftNode = NULL, *rightNode = NULL;

void check(TreeNode *cur) {
    if (pre != NULL && pre->val > cur->val) {
        if (leftNode == NULL) {
            leftNode = pre;
            rightNode = cur;
        } else {
            rightNode = cur;
        }
    }
    pre = cur;
}

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
    swap(leftNode->val, rightNode->val);
}

int main() {

}
