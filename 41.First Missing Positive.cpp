#include <iostream>
#include <vector>

using namespace std;

// Given an unsorted integer array, find the first missing positive integer.
int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
            swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i + 1)
            return i + 1;

    return nums.size() + 1;
}

int main() {
}
