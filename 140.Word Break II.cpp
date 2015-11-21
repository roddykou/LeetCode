#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<string>& ret, vector<string>& current, vector<vector<int> >& dp, const string& s, int pos) {
    if (pos == s.length()) {
        string sentence;
        for (string word : current)
            sentence += word + " ";
        ret.push_back(sentence.substr(0, sentence.length() - 1));
    } else {
        for (int len : dp[pos]) {
            current.push_back(s.substr(pos, len));
            dfs(ret, current, dp, s, pos + len);
            current.pop_back();
        }
    }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.length();
    vector<string> ret, current;
    vector<vector<int> > dp (s.length(), vector<int> ());
    for (int i = n - 1; i >= 0; i--)
        if (wordDict.find(s.substr(i)) != wordDict.end())
            dp[i].push_back(n - i);

    for (int i = n - 2; i >= 0; i--)
        if (!dp[i + 1].empty())
            for (int j = i; j >= 0; j--)
                if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
                    dp[j].push_back(i - j + 1);

    dfs(ret, current, dp, s, 0);
    return ret;
}

int main() {

}
