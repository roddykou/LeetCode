#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    if (word1.size() < word2.size())    return minDistance(word2, word1);
    if (word2.size() == 0)  return word1.size();

    vector<vector<int> > dp (word2.size(), vector<int> (word1.size(), 0));

    bool met = false;
    for (int j = 0; j < word1.size(); j++) {
        if (met || word1[j] == word2[0]) {
            dp[0][j] = j;
            met = true;
        } else {
            dp[0][j] = j + 1;
        }
    }
    met = false;
    /* can't from i = 1, maybe word1[0] == word2[0] */
    for (int i = 0; i < word2.size(); i++) {
        if (met || word2[i] == word1[0]) {
            dp[i][0] = i;
            met = true;
        } else {
            dp[i][0] = i + 1;
        }
    }

    for (int i = 1; i < word2.size(); i++)
        for (int j = 1; j < word1.size(); j++)
            if (word1[j] == word2[i])
                dp[i][j] = dp[i - 1][j - 1];
            else
                /* three possible edit ways, three possible transitions */
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;

    return dp[word2.size() - 1][word1.size() - 1];
}

int main () {
    // cout << minDistance("sea", "eat");
    // cout << minDistance("mart", "karma");
    // cout << minDistance("teacher", "tepache");
    cout << minDistance("teacher", "theater");
}
