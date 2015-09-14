#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int si = 0, pi = 0;
    /* avoid wrong answer when "aa", "a" */
    int pStar = p.length() + 1, sPrev = s.length();
    /* we never need to backtrace to previous '*'
     * cuz '*' Matches any sequence of characters,
     * meaning we only need to check if chars behind current '*'
     * match chars behind si pointer. */
    while(si < s.length()) {
        if (pi < p.length()) {
            if (p[pi] == '*') {
                pStar = pi++;
                sPrev = si;
            } else if (s[si] == p[pi] || p[pi] == '?') {
                si++;
                pi++;
            } else {
                pi = pStar;
                si = sPrev + 1;
            }
        } else {
            pi = pStar;
            si = sPrev + 1;
        }
    }
    while (pi < p.length() && p[pi] == '*') pi++;
    return pi == p.length();
}

bool isMatchDP(string s, string p) {
    /*
             a b e f c d g i e s c d f i m d e
           1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        a  0 1
        b  0 0 1
        *  0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
        c
        d
        ?
        i
        *
        d
        e

            a b
          1 0 0
        * 1 1 1
        a 0 1 0

    */
    vector<vector<bool> > dp (p.length() + 1, vector<bool> (s.length() + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= p.length() && dp[i - 1][0]; i++)
        if (p[i - 1] == '*')
            dp[i][0] = true;

    for (int i = 1; i <= p.length(); i++)
        for (int j = 1; j <= s.length(); j++)
            if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

    return dp[p.length()][s.length()];
}

int main() {
    // cout << isMatch("aa", "*") << endl;
    // cout << isMatch("", "*") << endl;
    // cout << isMatch("hi", "*?") << endl;
    // cout << isMatch("aa", "a") << endl;
    //               01234567890123456    0123456789
    // cout << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
    cout << isMatchDP("ab", "*a") << endl;
}
