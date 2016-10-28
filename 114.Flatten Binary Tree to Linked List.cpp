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

void flatten(TreeNode* root) {
    TreeNode *cur = root, *next = NULL;
    while (cur != NULL) {
        if (cur->left != NULL) {
            next = cur->left;
            while (next->right)
                next = next->right;
            next->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main() {

}
