#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    int ret = 0, num1, num2;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                ret = num1 + num2;
                s.push(ret);
        } else if (tokens[i] == "-") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                ret = num2 - num1;
                s.push(ret);
        } else if (tokens[i] == "*") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                ret = num1 * num2;
                s.push(ret);
        } else if (tokens[i] == "/") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                ret = num2 / num1;
                s.push(ret);
        } else {
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}

int main() {

}
