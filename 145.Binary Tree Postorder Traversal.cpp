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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root)  return ret;

    TreeNode *cur, *prev = root;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if (cur->left == NULL && cur->right == NULL) {
            s.pop();
            ret.push_back(cur->val);
            prev = cur;
        } else if (prev == cur->right ||
                   (prev == cur->left && cur->right == NULL)) {
             s.pop();
             ret.push_back(cur->val);
             prev = cur;
        } else {
            if (cur->right) s.push(cur->right);
            if (cur->left)  s.push(cur->left);
        }
    }
    return ret;
}

vector<int> postorderMorrisTraversal(TreeNode *root) {
    vector<int> ret;
    TreeNode dummy (0);
    dummy.left = root;

    TreeNode *cur = &dummy, *prev = NULL;
    while (cur != NULL) {
        if (cur->left != NULL) {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else if (prev->right == cur) {
                vector<int> tmp;
                for (TreeNode *t = cur->left; t != cur; t = t->right)
                    tmp.push_back(t->val);
                reverse(tmp.begin(), tmp.end());
                ret.insert(ret.end(), tmp.begin(), tmp.end());
                prev->right = NULL;
                cur = cur->right;
            }
        } else {
            cur = cur->right;
        }
    }
    return ret;
}

int main() {

}
