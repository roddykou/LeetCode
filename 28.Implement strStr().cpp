#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    int ret = -1;
    int m = haystack.length(), n  = needle.length();
    for (int i = 0; i < m - n + 1; i++) {
        int j = 0;
        while (j < n && haystack[i + j] == needle[j])
            j++;
        if (j == n)
            return i;
    }
    return ret;
}

int main () {
}
