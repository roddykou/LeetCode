#include <iostream>
#include <vector>

using namespace std;

int minCut(string s) {
    int n = s.length();
    vector<vector<bool> > isPalin (n, vector<bool> (n, false));
    vector<int> dp (n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >=0; j--) {
            if (s[i] == s[j] && (i - j < 2 || isPalin[i - 1][j + 1])) {
                isPalin[i][j] = true;
                dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    return dp[n - 1];
}

int main() {
    
}
