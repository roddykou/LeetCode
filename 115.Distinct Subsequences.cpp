#include <iostream>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
    if (s.length() < t.length() || s.empty() || t.empty())
        return 0;

    /* Can do it with vector<int> dp (s.size(), 0) */
    vector<vector<int> > dp (t.size(), vector<int> (s.size(), 0));

    dp[0][0] = (s[0] == t[0]);
    for (int j = 1; j < s.size(); j++)
        dp[0][j] = dp[0][j - 1] + (t[0] == s[j]);

    for (int i = 1; i < t.size(); i++)
        for (int j = i; j < s.size(); j++)
            /* caution the scope of (? :) */
            dp[i][j] = dp[i][j - 1] + (t[i] == s[j] ? dp[i - 1][j - 1] : 0);
    return dp[t.size() - 1][s.size() - 1];
}

int main () {
    
}
