#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ret;
    if (strs.size() == 0)
        return ret;

    for (int i = 0; i < strs[0].length(); i++) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++)
            if (i >= strs[j].length() || c != strs[j][i])
                return ret;
        ret += c;
    }
    return ret;
}

int main() {
}
