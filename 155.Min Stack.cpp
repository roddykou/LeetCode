#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<long> data;
    long mini;
public:
    void push(int x) {
        if (data.empty()) {
            data.push(0L);
            mini = x;
        } else {
            data.push(x - mini);
            if (x < mini)   mini = x;
        }
    }

    void pop() {
        if (data.empty())   return;
        if (data.top() < 0) mini = mini - data.top();
        data.pop();
    }

    int top() {
        if (data.top() > 0)
            return (int) (data.top() + mini);
        else
            return (int) mini;
    }

    int getMin() {
        return (int) mini;
    }
};

int main() {

}
