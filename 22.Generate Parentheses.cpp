#include <iostream>
#include <vector>

using namespace std;

void helper(vector<string> &ret, string current, int left, int right) {
    if (left == 0)
        ret.push_back(current + string (right, ')'));
    else if (left == right)
        helper(ret, current + "(", left - 1, right);
    else {
        helper(ret, current + "(", left - 1, right);
        helper(ret, current + ")", left, right - 1);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ret;
    helper(ret, "", n, n);
    return ret;
}

int main () {
    vector<string> r = generateParenthesis(3);
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << ",";
    cout << endl;
}

/*
(       ()
        1
((      (())    ()()
        02      11
(((     ((()))  (()())  ()(())  (())()  ()()()
        003     012     102     021     111

        0004    0013    0103    1003    0022    0112    1012    0202    1102    0031
*/
