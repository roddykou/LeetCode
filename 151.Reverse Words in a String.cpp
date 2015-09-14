#include <iostream>
#include <algorithm>

using namespace std;

void reverseWords(string &s) {
    int newI = 0, oldI = 0;
    while(oldI < s.length()) {
        if (s[oldI] == ' ') {
            oldI++;
            continue;
        }

        int wordStart = oldI;
        while (oldI < s.length() && s[oldI] != ' ')
            oldI++;

        /* - - - t h i s w o r d
         * d r o w s i h t
         * ^     ^             ^
         * |     |             |
         * newI wordStart   wordEnd
         */
        int wordEnd = oldI - 1, wordLen = wordEnd - wordStart + 1;
        int i = 0;
        while (i < wordLen && newI < wordStart) {
            s[newI++] = s[wordEnd--];
            i++;
        }

        if (i < wordLen) {
            newI = wordEnd + 1;
            while (wordStart < wordEnd)
                swap(s[wordStart++], s[wordEnd--]);
        }
        
        s[newI++] = ' ';
    }
    s.resize(max(newI - 1, 0));
    reverse(s.begin(), s.end());
}

int main() {
    // string s = "   the  sky  is  blue    ";
    // string s = "a";
    string s = "   a   b ";
    reverseWords(s);
    cout << s + '|' << endl;
}
