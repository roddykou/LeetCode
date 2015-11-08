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

class BSTIterator {
private:
    TreeNode *cur;
    stack<TreeNode *> s;

public:
    BSTIterator(TreeNode *root) {
        cur = root;
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        cur = s.top();
        s.pop();
        int ret = cur->val;
        cur = cur->right;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        return ret;
    }
};

int main() {

}
