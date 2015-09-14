#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    // return !left ? right : !right ? left : root;
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        // [1,2,3], node with value 2, node with value 3
        return root;
    }
}

int main() {
    
}
