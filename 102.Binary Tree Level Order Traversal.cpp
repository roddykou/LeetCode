#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    if (root == NULL)   return ret;

    vector<int> level;
    queue<TreeNode *> q;
    q.push(root), q.push(NULL);
    while (q.size() > 1) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == NULL) {
            ret.push_back(level);
            level.clear();
            q.push(NULL);
        } else {
            level.push_back(cur->val);
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    ret.push_back(level);
    return ret;
}

int main() {

}
