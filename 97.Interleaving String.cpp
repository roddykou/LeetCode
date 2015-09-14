#include <iostream>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())   return false;

    // bool dp[s2.length() + 1][s1.length() + 1] = {false};
    vector<vector<int> > dp (s2.length() + 1, vector<int> (s1.length() + 1, false));

    dp[0][0] = true;
    for (int j = 1; j <= s1.length(); j++)
        dp[0][j] = dp[0][j - 1] && (s1[j - 1] == s3[j - 1]);

    for (int i = 1; i <= s2.length(); i++)
        dp[i][0] = dp[i - 1][0] && (s2[i - 1] == s3[i - 1]);

    for (int i = 1; i <= s2.length(); i++) {
        for (int j = 1; j <= s1.length(); j++) {
            dp[i][j] = (dp[i - 1][j] && (s3[i + j - 1] == s2[i - 1])) ||
                       (dp[i][j - 1] && (s3[i + j - 1] == s1[j - 1]));
        }
    }
    return dp[s2.length()][s1.length()];
}

int main() {

}
