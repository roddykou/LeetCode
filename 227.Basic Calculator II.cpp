#include <iostream>

using namespace std;

int getNumber(string& s, int& i) {
    while (s[i] == ' ') i++;
    int j = i;
    while (j < s.length() && s[j] >= '0' && s[j] <= '9')    j++;
    int ret = stoi(s.substr(i, j - i + 1));
    i = j;
    return ret;
}

int calculate(string s) {
    int sign = 1, ret = 0, i = 0, tmp = getNumber(s, i);
    while (i < s.length()) {
        // cout << "i: " << i << " tmp: " << tmp << " ret: " << ret << endl;
        if (s[i] == '+' || s[i] == '-') {
            ret += tmp * sign;
            sign = s[i] == '+' ? 1 : -1;
            tmp = getNumber(s, ++i);
        } else if (s[i] == '*') {
            tmp *= getNumber(s, ++i);
        } else if (s[i] == '/') {
            tmp /= getNumber(s, ++i);
        } else {
            i++;
        }
    }
    return ret + tmp * sign;
}

int main () {
    cout << calculate("3*5/2-9/3") << endl;
    cout << calculate("3          ") << endl;
    cout << calculate("1   +    1") << endl;
}
