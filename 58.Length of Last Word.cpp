#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int ret = 0;
    for (int i = s.length() - 1; i >=0; i--) {
        if (s[i] == ' ')
            if (ret == 0)
                continue;
            else
                break;
        else
            ret++;
    }
    return ret;
}

int main() {
}
