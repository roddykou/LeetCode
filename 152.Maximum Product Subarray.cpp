#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int tmp = 1, ret = INT_MIN, n = nums.size();
    for (int i = 0; i < n; i++) {
        tmp *= nums[i];
        ret = max(ret, tmp);
        if (tmp == 0)   tmp = 1;
    }
    tmp = 1;
    for (int i = n - 1; i >= 0; i--) {
        tmp *= nums[i];
        ret = max(ret, tmp);
        if (tmp == 0)   tmp = 1;
    }
    return ret;
}

int main() {
}
