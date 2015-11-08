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

TreeNode *dfs(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
    if (ps == pe)   return NULL;

    int value = postorder[pe - 1];
    int index = find(inorder.begin() + is, inorder.begin() + ie, value) - inorder.begin();

    TreeNode *root = new TreeNode (value);
    root->left = dfs(inorder, is, index, postorder, ps, ps + index - is);
    root->right = dfs(inorder, index + 1, ie, postorder, ps + index - is, pe - 1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return dfs(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}

int main() {

}
