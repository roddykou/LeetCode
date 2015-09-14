#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val)    return lowestCommonAncestor(root, q, p);

    TreeNode *runner = root;
    while (runner != NULL) {
        if (runner->val >= p->val && runner->val <= q->val)
            break;
        else if (runner->val < p->val)
            runner = runner->right;
        else if (runner->val > q->val)
            runner = runner->left;
        else
            cout << "FUCK" << endl;
    }
    return runner;
}

int main() {

}
