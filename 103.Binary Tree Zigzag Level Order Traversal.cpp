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

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > ret;
    if (root == NULL)   return ret;

    bool left2right = true;
    vector<int> level;
    queue<TreeNode *> q;
    q.push(root), q.push(NULL);
    while (q.size() > 1) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur == NULL) {
            if (!left2right)
                reverse(level.begin(), level.end());
            left2right = !left2right;
            ret.push_back(level);
            level.clear();
            q.push(NULL);
        } else {
            level.push_back(cur->val);
            if (cur->left)  q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    if (!left2right)
        reverse(level.begin(), level.end());
    ret.push_back(level);
    return ret;
}

int main() {

}
