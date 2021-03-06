#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[end]) {
            if (nums[mid] < target && target <= nums[end])
                start = mid +1;
            else
                end = mid - 1;
        } else {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main () {
}
