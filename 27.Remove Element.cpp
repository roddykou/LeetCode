#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val)
            swap(nums[i], nums[ret++]);
    }
    return ret;
}

int main() {
}
