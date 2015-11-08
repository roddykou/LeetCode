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

TreeNode *clone(TreeNode *root) {
    if (root == NULL)   return NULL;

    TreeNode *newNode = new TreeNode (root->val);
    newNode->left = clone(root->left);
    newNode->right = clone(root->right);
    return newNode;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode *> ret, prev;
    ret.push_back(NULL);
    prev.push_back(new TreeNode (1));

    if (n == 0) return ret;
    if (n == 1) return prev;

    for (int i = 2; i <= n; i++) {
        ret.clear();
        TreeNode *newNode = new TreeNode (i);

        for (int j = 0; j < prev.size(); j++) {
            TreeNode *prevRoot = prev[j], *prevRunner = prev[j];

            newNode->left = prevRunner;
            ret.push_back(clone(newNode));
            newNode->left = NULL;

            while (prevRunner != NULL) {
                newNode->left = prevRunner->right;
                prevRunner->right = newNode;
                ret.push_back(clone(prevRoot));

                prevRunner->right = newNode->left;
                newNode->left = NULL;
                prevRunner = prevRunner->right;
            }
        }
        prev = ret;
    }
    return ret;
}

int main() {

}
