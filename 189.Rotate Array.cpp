#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.begin() + nums.size() - k);
    reverse(nums.begin() + nums.size() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main () {
    // For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
}
