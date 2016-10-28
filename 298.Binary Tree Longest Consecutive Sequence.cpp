#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, int cur, TreeNode *pre, int& ret) {
   if(root == nullptr)
      return;
   if(root->val == pre->val + 1)
      cur++;
   else
      cur = 1;

   ret = max(ret, cur);
   dfs(root->left, cur, root, ret);
   dfs(root->right, cur, root, ret);
}

int longestConsecutive(TreeNode *root) {
   int ret = 0;
   if (root == nullptr)
      return 0;
   dfs(root, 0, root, ret);
   return ret;
}


int main() {

}
