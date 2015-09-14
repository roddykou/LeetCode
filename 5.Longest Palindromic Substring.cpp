#include <iostream>
#include <vector>

using namespace std;

string longestPalindromeDP(string s) {
    int len = s.length(), left = 0, right = 0;
    vector<vector<bool> > dp (len, vector<bool> (len, false));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j)
                dp[i][j] = true;
            else if (i - 1 == j)
                dp[i][j] = s[i] == s[j];
            else
                dp[i][j] = dp[i - 1][j + 1] && s[i] == s[j];

            if (dp[i][j] && i - j > right - left)
                left = j, right = i;
        }
    }

    return s.substr(left, right - left + 1);
}

int longestPalinFromCenter(string& s, int i, int& start) {
    int left = i, right = i;
    while (left >= 0 && right < s.length() && s[left] == s[right])
        left--, right++;
    /* note here: left & right already doesn't match */
    int len = right - left - 1;
    start = left + 1;

    /* the center of palindrome can start from the middle of two chars */
    left = i, right = i + 1;
    while (left >= 0 && right < s.length() && s[left] == s[right])
        left--, right++;
    if (len < right - left - 1) {
        len = right - left - 1;
        start = left + 1;
    }
    return len;
}

string longestPalindrome(string s) {
    int start = 0, len = INT_MIN;
    for (int i = 0; i < s.length(); i++) {
        int tmpStart = 0;
        int tmpLen = longestPalinFromCenter(s, i, tmpStart);
        if (tmpLen > len) {
            len = tmpLen;
            start = tmpStart;
        }
    }
    return s.substr(start, len);
}

int main() {
    cout << longestPalindrome("a") << endl;
}
