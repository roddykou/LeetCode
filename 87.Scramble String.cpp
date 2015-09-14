#include <iostream>
#include <vector>

using namespace std;

bool isScramble(string s1, string s2) {
    if (s1 == s2)   return true;

    int len = s1.length();
    vector<int> table (26, 0);
    for (int i = 0; i < len; i++) {
        table[s1[i] - 'a']++;
        table[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (table[i] != 0)
            return false;

    for (int i = 1; i < len; i++)
        if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
            (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))))
            return true;

    return false;
}

int main() {
}
