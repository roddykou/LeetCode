#include <vector>
#include <iostream>

using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp (n, false);
    for (int i = 0; i <= nums[0]; i++)
        dp[i] = true;

    for (int i = 1; i < n; i++) {
        if (dp[i]) {
            if (i + nums[i] >= n)
                return true;
            for (int j = (i - 1) + nums[i - 1]; j <= i + nums[i]; j++)
                dp[j] = true;
        }
    }

    return dp[n - 1];
}

int main () {
    int a[] = {9,8,7,6,5,4,3,2,1};
    vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
    cout << canJump(v) << endl;
}
