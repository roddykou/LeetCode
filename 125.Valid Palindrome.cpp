#include <iostream>

using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (!isalnum(s[l]))
            l++;
        else if (!isalnum(s[r]))
            r--;
        else if (tolower(s[l++]) != tolower(s[r--]))
            return false;
    }
    return true;
}

int main () {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
}
