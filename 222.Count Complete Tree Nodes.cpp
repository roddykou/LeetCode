#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int leftDepth(TreeNode *root) {
    int ret = 0;
    while (root) {
        ret++;
        root = root->left;
    }
    return ret;
}

int rightDepth(TreeNode *root) {
    int ret = 0;
    while (root) {
        ret++;
        root = root->right;
    }
    return ret;
}

int countNodes(TreeNode* root) {
    int ret = 0;
    while (root) {
        int lld = leftDepth(root->left), lrd = rightDepth(root->left), rrd = rightDepth(root->right);
        // cout << lld << lrd << rrd << endl;
        if (lld == rrd) {
            ret += pow(2, lld + 1) - 1;
            break;
        } else if (lld == lrd) {
            ret += pow(2, lld);
            root = root->right;
        } else {
            ret += pow(2, rrd);
            root = root->left;
        }
    }

    return ret;
}

int main() {

}
