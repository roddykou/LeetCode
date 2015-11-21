#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root) {
    if (!root)  return true;

    stack<TreeNode *> s;
    TreeNode *prev = NULL, *cur = root;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if (cur != NULL) {
            s.push(cur->left);
        } else {
            s.pop();
            if (!s.empty()) {
                cur = s.top();
                if (prev && prev->val >= cur->val)
                    return false;
                prev = cur;
                s.pop();
                s.push(cur->right);
            }
        }
    }
    return true;
}

int main() {

}
