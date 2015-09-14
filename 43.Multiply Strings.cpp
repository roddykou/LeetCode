#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> v (num1.size() + num2.size(), 0);
    int carry = 0, tmp;
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            tmp = (num1[i] - '0') * (num2[j] - '0') + carry + v[i + j + 1];
            v[i + j + 1] = tmp % 10;
            carry = tmp / 10;
        }
        tmp = carry + v[i];
        v[i] = tmp % 10;
        carry = tmp / 10;
    }
    string ret;
    int i = 0;
    while (i < v.size() && v[i] == 0)   i++;
    while (i < v.size())    ret.push_back(v[i++] + '0');
    return ret;
}

int main() {
}
