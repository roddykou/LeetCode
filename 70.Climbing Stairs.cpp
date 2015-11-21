#include <iostream>
#include <vector>

using namespace std;

// 1 1 2 3
int climbStairs(int n) {
    vector<int> dp (n + 1, 1);
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int main() {
    
}
