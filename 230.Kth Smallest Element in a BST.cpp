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

int kthSmallest(TreeNode* root, int k) {
    int number = 1;
    TreeNode *top = NULL;
    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty()) {
        top = s.top();
        s.pop();
        if (top != NULL) {
            s.push(top->right);
            s.push(top);
            s.push(top->left);
        } else {
            if (s.empty())
                break;
            else if (number == k)
                return s.top()->val;
            else {
                s.pop();
                number++;
            }
        }
    }
    return -1;
}

int main() {

}
