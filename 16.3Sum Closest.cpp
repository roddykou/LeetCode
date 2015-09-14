#include <vector>
#include <iostream>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int diff = INT_MAX;
    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
                return target;
            else if (sum < target)
                j++;
            else
                k--;
            if (abs(sum - target) < abs(diff))
                diff = sum - target;
        }
    }
    return target + diff;
}

int main() {
}
