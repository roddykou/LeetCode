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

TreeNode *dfs(vector<int>& nums, int start, int end) {
    if (start > end)    return NULL;

    int mid = (start + end) / 2;
    TreeNode *ret = new TreeNode(nums[mid]);
    ret->left = dfs(nums, start, mid - 1);
    ret->right = dfs(nums, mid + 1, end);
    return ret;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
}

int main() {

}
