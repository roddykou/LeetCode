#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.empty())   return ret;
    sort(nums.begin(), nums.end());
    ret.push_back(nums);
    int i, j;
    while (true) {
        for (i = nums.size() - 1; i > 0 && nums[i] <= nums[i - 1]; i--)  ;
        if (i == 0) break;
        for (j = nums.size() - 1; j > i - 1 && nums[j] <= nums[i - 1]; j--)  ;
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
        ret.push_back(nums);
    }

    return ret;
}

int main() {

}
