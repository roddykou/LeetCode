#include <iostream>
#include <vector>

using namespace std;

// Binay Index Tree
/*
class NumArray {
public:
    NumArray(vector<int> &nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i + 1; j < num.size(); j += (j&-j)) {
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }    
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};
*/

// Segment Tree
// 21:30
class Node {
public:
    Node(int s, int e, int v) {
        startIdx = s;
        endIdx = e;
        sum = v;
        left = nullptr;
        right = nullptr;
    }

    int startIdx, endIdx, sum;
    Node *left, *right;
};

class NumArray {
public:
    Node *buildTree(vector<int>& nums, int start, int end) {
        if (start == end) {
            return new Node(start, end, nums[start]);
        }
        
        int mid = (start + end) / 2;
        Node *left = buildTree(nums, start, mid);
        Node *right = buildTree(nums, mid + 1, end);
        Node *root = new Node(start, end, left->sum + right->sum);
        root->left = left;
        root->right = right;
        return root;
    }

    NumArray(vector<int> &nums) {
        root = nums.empty() ? new Node(0, 0, 0) : 
                              buildTree(nums, 0, nums.size() - 1);
    }
    
    void dfsUpdate(int idx, int val, Node *root) {
        if (idx < root->startIdx || idx > root->endIdx)
            return;
            
        if (root->startIdx == root->endIdx && root->startIdx == idx) {
            root->sum = val;
            return;
        }
            
        int mid = (root->startIdx + root->endIdx) / 2;
        if (idx <= mid)
            dfsUpdate(idx, val, root->left);
        else
            dfsUpdate(idx, val, root->right);
        root->sum = root->left->sum + root->right->sum;
    }
    
    void update(int idx, int val) {
        dfsUpdate(idx, val, root);
    }
    
    int dfsSumRange(int i, int j, Node *root) {
        if (root->startIdx == i && root->endIdx == j)
            return root->sum;
        else if (i > root->endIdx || j < root->startIdx || i > j)
            return 0;
        
        int mid = (root->startIdx + root->endIdx) / 2;
        return dfsSumRange(i, min(j, mid), root->left) +
               dfsSumRange(max(i, mid + 1), j, root->right);
    }
    
    int sumRange(int i, int j) {
        return dfsSumRange(i, j, root);
    }    


private:
    Node *root = nullptr;
};

int main() {
    vector<int> v = {0, 9, 5, 7 ,3};
    NumArray n(v);
    cout << n.sumRange(4,4) << endl;    // 3
    cout << n.sumRange(2,4) << endl;    // 15
    cout << n.sumRange(3,3) << endl;    // 7
    n.update(4,5);
    n.update(1,7);
    n.update(0,8);
    cout << n.sumRange(1,2) << endl;    // 12
    n.update(1,9);
    cout << n.sumRange(4,4) << endl;    // 5
    n.update(3,4);
}