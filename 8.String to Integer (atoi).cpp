#include <iostream>

using namespace std;

int myAtoi(string str) {
    int i = 0;
    while (i < str.length() && str[i] == ' ')	i++;

    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    long ret = 0;
    while (i < str.length()) {
        char c = str[i];
        if (c < '0' || c > '9') break;
        ret = ret * 10 + c - '0';
        if (sign == 1 && ret >= INT_MAX)    return INT_MAX;
        if (sign == -1 && -ret <= INT_MIN)  return INT_MIN;
        i++;
    }
    return ret * sign;
}

int main() {

}
