#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> stk;
    stk.push('*');
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);
        else {
            char top = stk.top();
            if ((top == '(' && s[i] == ')') ||
                (top == '[' && s[i] == ']') ||
                (top == '{' && s[i] == '}'))
                stk.pop();
            else
                return false;
        }
    }
    return stk.top() == '*';
}

int main() {
}
