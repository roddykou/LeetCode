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

TreeNode *dfs(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
    if (ps == pe)   return NULL;

    int value = preorder[ps];
    int index = find(inorder.begin() + is, inorder.begin() + ie, value) - inorder.begin();

    TreeNode *root = new TreeNode (value);
    root->left = dfs(preorder, ps + 1, ps + 1 + index - is, inorder, is, index);
    root->right = dfs(preorder, ps + 1 + index - is, pe, inorder, index + 1, ie);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return dfs(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

int main() {

}
