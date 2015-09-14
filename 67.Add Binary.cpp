#include <iostream>

using namespace std;

string addBinary(string a, string b) {
    if (a.length() < b.length())    return addBinary(b, a);

    int sum = 0, carry = 0, i = a.length() - 1, j = b.length() - 1;
    while (j >= 0) {
        sum = carry + a[i] - '0' + b[j] - '0';
        a[i] = '0' + (sum % 2);
        carry = sum / 2;
        i--;
        j--;
    }

    while (i >= 0) {
        if (carry == 0)
            return a;
        if (a[i] == '0') {
            a[i] = '1';
            return a;
        } else {
            a[i] = '0';
            carry = 1;
        }
        i--;
    }

    if (carry == 1)
        return '1' + a;
    else
        return a;
}

int main() {
}
