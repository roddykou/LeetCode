#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ret;
    if (nums.size() < 3)   return ret;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2;) {
        int target = 0 - nums[i];
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                vector<int> cur;
                cur.push_back(nums[i]);
                cur.push_back(nums[left]);
                cur.push_back(nums[right]);
                ret.push_back(cur);
                while (left < right && nums[left] == cur[1])    left++;
                while (left < right && nums[right] == cur[2])   right--;
            }
        }
        while (i < nums.size() - 2 && nums[i] + target == 0)    i++;
    }
    return ret;
}

int main () {
}
