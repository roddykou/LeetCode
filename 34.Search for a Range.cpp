#include <vector>
#include <iostream>

using namespace std;
// Given a sorted array of integers, find the starting and ending position of a given target value.
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret (2, -1);
    int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] < target) {
            start = mid + 1;
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            int leftEnd = mid, leftMid = (start + leftEnd) / 2;
            while (start < leftEnd) {
                if (nums[leftMid] == target) {
                    leftEnd = leftMid;
                } else {
                    start = leftMid + 1;
                }
                leftMid = (start + leftEnd) / 2;
            }
            ret[0] = leftEnd;

            int rightStart = mid, rightMid = (rightStart + end + 1) / 2;
            while (rightStart < end) {
                if (nums[rightMid] == target) {
                    rightStart = rightMid;
                } else {
                    end = rightMid - 1;
                }
                rightMid = (rightStart + end + 1) / 2;
            }
            ret[1] = rightStart;
            break;
        }
        mid = (start + end) / 2;
    }
    return ret;
}

int main () {
    int a[] = {1,2,3,3,3,3,4,5,9};
    vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
    vector<int> result = searchRange(v, 3);
    cout << result[0] << ", " << result[1] << endl;
}
