#include <iostream>
#include <vector>

using namespace std;

/* 110 */
int numDecodings(string s) {
    if (s.empty())  return 0;
    vector<int> dp (s.length() + 1, 0);
    dp[0] = 1;
    dp[1] = (s[0] == '0') ? 0 : 1;
    for (int i = 2; i <= s.length() && dp[i - 1] != 0; i++) {
        char cur = s[i - 1], pre = s[i - 2];
        if (pre == '0')
            dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
        else if (pre == '1' && cur == '0')
            dp[i] = dp[i - 2];
        else if (pre == '1')
            dp[i] = dp[i - 1] + dp[i - 2];
        else if (pre == '2' && cur == '0')
            dp[i] = dp[i - 2];
        else if (pre == '2')
            dp[i] = cur > '0' && cur <= '6' ? dp[i - 1] + dp[i - 2] : dp[i - 1];
        else
            /* 230 */
            dp[i] = cur == '0' ? 0 : dp[i - 1];
    }
    return dp[s.length()];
}

int main() {
    cout << numDecodings("10") << endl;
}
