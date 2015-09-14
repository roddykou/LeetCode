#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> table (256, -1);
    int ret = 0, start = 0, tmpRet = 0;
    for (int i = 0; i < s.length(); i++) {
        if (table[s[i]] == -1 || table[s[i]] < start) {
            tmpRet++;
            table[s[i]] = i;
        } else {
            start = table[s[i]] + 1;
            table[s[i]] = i;
            ret = max(ret, tmpRet);
            tmpRet = i - start + 1;
        }
    }
    /* all distinct characters edge case */
    return max(ret, tmpRet);
}

int main() {
    cout << lengthOfLongestSubstring("abcdab") << endl;
    cout << lengthOfLongestSubstring("c") << endl;
}