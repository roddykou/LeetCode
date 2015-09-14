#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int longestValidParenthesesUsingStack(string s) {
    stack<int> stk;
    stk.push(-1);
    int ret = 0;
    for(int i = 0; i < s.size(); i++) {
        int t = stk.top();
        if(t != -1 && s[i] == ')' && s[t] == '(') {
            stk.pop();
            ret = max(ret, i - stk.top());
        } else
            stk.push(i);
    }
    return ret;
}

int longestValidParentheses(string s) {
    int l2r = 0, r2l = 0, ret = 0, breakage = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            l2r++;
            breakage++;
        } else {
            breakage--;
            if (breakage == 0)
                ret = max(ret, l2r);
            if (breakage < 0) {
                breakage = 0;
                l2r = 0;
            }
        }
    }

    breakage = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') {
            r2l++;
            breakage++;
        } else {
            breakage--;
            if (breakage == 0)
                ret = max(ret, r2l);
            if (breakage < 0) {
                breakage = 0;
                r2l = 0;
            }
        }
    }
    return ret * 2;
}

int main () {
}
