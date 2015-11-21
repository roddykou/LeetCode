#include <iostream>
#include <stack>

using namespace std;

/* "(1+(4+5+2)-3)+(6+8)" = 23 */
int calculate(string s) {
    stack<char> ops;
    stack<int> nums;

    // Tricky
    ops.push('(');
    s += ')';

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(' || c == '-' || c == '+') {
            ops.push(c);
        } else if (c == ')') {
            int result = 0;

            // use while loop
            while (ops.top() != '(') {
                if (ops.top() == '+')
                    result += nums.top();
                else if (ops.top() == '-')
                    result -= nums.top();
                ops.pop();
                nums.pop();
            }
            result += nums.top();
            nums.pop();
            ops.pop();
            nums.push(result);
        } else if (c != ' ') {
            int number = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (int) (s[i] - '0');
                i++;
            }
            i--;
            nums.push(number);
        }
    }
    return nums.top();
}

int main() {

}
