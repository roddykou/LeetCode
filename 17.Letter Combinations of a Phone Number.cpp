#include <iostream>
#include <vector>

using namespace std;

                 /* 2      3      4      5      6      7       8       9   */
string dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
    vector<string> ret, pre (1, "");
    for (int i = 0; i < digits.length(); i++) {
        ret.clear();
        string letters = dict[digits[i] - '2'];
        for (int j = 0; j < pre.size(); j++)
            for (int k = 0; k < letters.length(); k++)
                ret.push_back(pre[j] + letters[k]);
        pre = ret;
    }
    return ret;
}

int main() {
    vector<string> r = letterCombinations("23");
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << ", ";
    cout << endl;
}
