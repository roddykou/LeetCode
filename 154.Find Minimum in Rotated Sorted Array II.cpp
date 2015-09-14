#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] < nums[end])
            end = mid;
        else if (nums[mid] > nums[end])
            start = mid + 1;
        else
            end--;
        mid = (start + end) / 2;
    }
    return nums[start];
}

int main() {
}
