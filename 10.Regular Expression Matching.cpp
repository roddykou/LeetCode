#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    vector<vector<bool> > dp (p.length() + 1, vector<bool> (s.length() + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= p.length(); i++) {
        if (p[i - 1] == '*') {
            dp[i][0] = dp[i - 2][0];
        }
    }

    for (int i = 1; i <= p.length(); i++) {
        for (int j = 1; j <= s.length(); j++) {
            if (p[i - 1] == '.' || p[i - 1] == s[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && (p[i - 2] == '.' || p[i - 2] == s[j - 1]));
        }
    }

    return dp[p.length()][s.length()];
}

//  Text: a-z, A-Z, 0-9
//  Pattern: a-z, A-z, 0-9, +, *
//  + = 1 or more times
//  * = 0 or more times.
//
//  Pattern: a*b
//  Text: aab, b return true
//
//  Pattern: a+b*
//  Text: aab, aa  return true
bool isMatch2(string s, string p) {
   vector<vector<bool> > dp (p.length() + 1, vector<bool> (s.length() + 1, false));
   dp[0][0] = true;
   for (int i = 1; i <= p.length(); i++) {
      for (int j = 1; j <= s.length(); j++) {
         if (p[i - 1] == s[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
         } else if (p[i - 1] == '+') {
            dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - 1]) && (p[i - 2] == s[j - 1]);
         } else if (p[i - 1] == '*') {
            dp[i][j] = dp[i - 2][j] || ((dp[i - 1][j] || dp[i - 1][j - 1]) && (p[i - 2] == s[j - 1]));
         }
      }
   }
   return dp[p.length()][s.length()];
}
int main () {
   //  cout << isMatch("aa", "a*") << endl;
   //  cout << isMatch("aaba", "ab*a*c*a") << endl;
   cout << isMatch2("aab", "a+b") << endl;//true
   cout << isMatch2("aab", "aab") << endl;//true
   cout << isMatch2("aab", "aa*b") << endl;//true
   cout << isMatch2("aab", "a+b*") << endl;//true
   cout << isMatch2("aab", "aa+b") << endl;//true
   cout << isMatch2("aab", "a+b+") << endl;//true
   cout << isMatch2("aab", "a+b*") << endl;//true
   cout << isMatch2("aab", "aaa+b") << endl;//false
   cout << isMatch2("aab", "a+bb+") << endl;//false
}
