#include <iostream>
#include <vector>

using namespace std;

// 1, 11, 21, 1211, 111221, ...
string countAndSay(int n) {
    string ret = "1";
    for (int i = 2; i <= n; i++) {
        string next = "";
        int j = 1, dup = 1;
        char number = ret[0];
        while (j < ret.length()) {
            if (ret[j] == number) {
                dup++;
            } else {
                next += to_string(dup) + number;
                number = ret[j];
                dup = 1;
            }
            j++;
        }
        ret = next + to_string(dup) + number;
    }
    return ret;
}

int main() {
    cout << countAndSay(4) << endl;
}
