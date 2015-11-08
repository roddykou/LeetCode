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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode *> s;

    if (root != NULL)   s.push(root);
    while (!s.empty()) {
        TreeNode *top = s.top();
        s.pop();
        ret.push_back(top->val);
        if (top->right != NULL) s.push(top->right);
        if (top->left != NULL) s.push(top->left);
    }
    return ret;
}

vector<int> preorderMorrisTraversal(TreeNode *root) {
    vector<int> ret;
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL) {
        if (cur->left != NULL) {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = cur;
                ret.push_back(cur->val);
                cur = cur->left;
            } else if (prev->right == cur) {
                prev->right = NULL;
                cur = cur->right;
            }
        } else {
            ret.push_back(cur->val);
            cur = cur->right;
        }
    }
    return ret;
}

int main() {

}
