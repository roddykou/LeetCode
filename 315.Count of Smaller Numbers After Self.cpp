#include <iostream>
#include <vector>

using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    vector<int> rightNums, res(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
        int left = 0, right = rightNums.size(); // right index starts with .size() not .size() - 1 
        while (left < right) {
            int mid = (right + left) / 2;
            if (rightNums[mid] >= nums[i]) right = mid;
            else left = mid + 1;
        }
        res[i] = right;
        rightNums.insert(rightNums.begin() + right, nums[i]);
    }
    return res;
}

struct Node {
    int val, index, count;
    Node(int v, int i, int c) : val(v), index(i), count(c) {}
};
 
void combine(vector<Node *>& mergeList, int start, int end) {
    vector<Node *> tmp;
    int mid = (start + end) / 2;
    int leftStart = start, leftEnd = mid, rightStart = mid + 1, rightEnd = end;
    int leftRunner = leftStart, rightRunner = rightStart;
    while (leftRunner <= leftEnd && rightRunner <= rightEnd) {
        if (mergeList[leftRunner]->val <= mergeList[rightRunner]->val) {
            mergeList[leftRunner]->count += rightRunner - rightStart;
            tmp.push_back(mergeList[leftRunner]);
            leftRunner++;
        } else {
            tmp.push_back(mergeList[rightRunner++]);
        }
    }

    while (leftRunner <= leftEnd) {
        mergeList[leftRunner]->count += rightRunner - rightStart;
        tmp.push_back(mergeList[leftRunner]);
        leftRunner++;
    }

    while (rightRunner <= rightEnd) {
        tmp.push_back(mergeList[rightRunner++]);
    }

    for (int i = start; i <= end; i++) {
        mergeList[i] = tmp[i - start];
    }
}

void mergeSort(vector<Node *>& mergeList, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(mergeList, start, mid);
        mergeSort(mergeList, mid + 1, end);
        combine(mergeList, start, end);
    }
}

vector<int> countSmallerMergeSort(vector<int>& nums) {
    vector<int> ret (nums.size(), 0);
    vector<Node *> mergeList;
    for (int i = 0; i < nums.size(); i++)
        mergeList.push_back(new Node(nums[i], i, 0));
    mergeSort(mergeList, 0, nums.size() - 1);
    for (int i = 0; i < mergeList.size(); i++)
        ret[mergeList[i]->index] = mergeList[i]->count;
    return ret;
}

// 21:26 - 21:46
int main() {
    vector<int> v = {5, 2, 6, 1};
    vector<int> r = countSmallerMergeSort(v);
    for (int n : r)
        cout << n << ", ";
    cout << endl;
}