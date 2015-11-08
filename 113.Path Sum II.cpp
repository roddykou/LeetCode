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

void dfs(TreeNode *root, vector<vector<int> >& ret, vector<int>& curPath, const int sum, const int curSum) {
    if (root->left == NULL && root->right == NULL) {
        if (curSum == sum)
            ret.push_back(curPath);
    }

    if (root->left != NULL) {
        curPath.push_back(root->left->val);
        dfs(root->left, ret, curPath, sum, curSum + root->left->val);
    }

    if (root->right != NULL) {
        curPath.push_back(root->right->val);
        dfs(root->right, ret, curPath, sum, curSum + root->right->val);
    }
    curPath.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<vector<int> > ret;
    vector<int> curPath;
    if (root != NULL) {
        curPath.push_back(root->val);
        dfs(root, ret, curPath, sum, root->val);
    }
    return ret;
}

int main() {

}
