#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    vector<bool> dp (s.length() + 1, false);
    dp[0] = true;

    for (int i = 0; i < s.length(); i++) {
        if (dp[i]) {
            if (wordDict.find(s.substr(i, s.length() - i)) != wordDict.end())
                return true;
            for (int j = i + 1; j < s.length(); j++) {
                if(wordDict.find(s.substr(i, j - i)) != wordDict.end()) {
                    dp[j] = true;
                }
            }
        }
    }
    return dp[s.length()];
}

int main() {

}
