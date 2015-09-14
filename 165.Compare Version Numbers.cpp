#include <iostream>
#include <vector>

using namespace std;

int getNumber(string& s, int& i) {
    if (i >= s.length())
        return 0;

    int j = i;
    while(j < s.length() && s[j] != '.')
        j++;
    int ret = stoi(s.substr(i, j - i));
    i = j + 1;
    return ret;
}

int compareVersion(string version1, string version2) {
    int i1 = 0, i2 = 0;
    while (i1 < version1.length() || i2 < version2.length()) {
        int number1 = getNumber(version1, i1);
        int number2 = getNumber(version2, i2);
        if (number1 > number2)
            return 1;
        else if (number1 < number2)
            return -1;
    }
    return 0;
}

int main() {
    cout << compareVersion("1.0", "1") << endl;
}
