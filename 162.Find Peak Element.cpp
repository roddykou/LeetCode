#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
    while (start < end) {
        if (nums[mid] < nums[mid + 1])
            start = mid + 1;
        else if (nums[mid] > nums[mid + 1])
            end = mid;
        mid = (start + end) / 2;
    }
    return start;
}

int main() {
}
