#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string shortestPalindrome(string s) {
    int palinEnd = 0;
    for (int i = 0; i < s.length(); i++) {
        int left = 0, right = i;
        while (left < right && s[left] == s[right])
            left++, right--;
        if (left >= right)
            palinEnd = i;
    }

    string insert = s.substr(palinEnd + 1);
    reverse(insert.begin(), insert.end());
    return insert + s;
}

string shortestPalindromeKMP(string s) {
    /* Build up a string cat the original and reverse */
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string l = s + "#" + rev_s;
    // string l = s;

    /* Use the prefix function / table in KMP */
    vector<int> p(l.size(), 0);
    for (int i = 1; i < l.size(); i++) {
        /* means j chars before i matches
         * the first j chars at the beginning of the string */
        int j = p[i - 1];

        /* if the next char from the suffix doesn't match the next char from prefix,
         * shorten the j. The next potential is jth element from prefix table (p[j-1])
         *  a a a a b a a a a b a a a a a
         *  0 1 2 3 0 1 2 3 4 5 6 7 8 9 4
         * 1st try match a a a a b a a a a b    p[i - 1] = 9 try match 10th char
         *             & a a a a b a a a a a
         * 2nd try match a a a a b              p[9 - 1] = 4 try match 5th char
         *               a a a a a
         * 3rd try match a a a a                p[4 - 1] = 3 try match 4th char
         *               a a a a*/
        while (j > 0 && l[i] != l[j]) {
            j = p[j - 1];
        }

        /* if we break the while loop because l[i] == l[j], increment j */
        p[i] = (j += l[i] == l[j]);
        cout << p[i];
    }
    cout << endl;

    /* Build up the return value */
    return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
}

int main() {
    // cout << shortestPalindromeKMP("acecaxb") << endl;
    cout << shortestPalindromeKMP("aaaabaaaabaaaaa") << endl;
    // cout << shortestPalindromeKMP("ababbbabbaba") << endl;
    // cout << shortestPalindromeKMP("aaaaacdaaaaa") << endl;
}
