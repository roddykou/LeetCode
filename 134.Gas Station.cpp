#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(), i = 0;
    while (i < n) {
        int gas_left = 0, j = 0;
        for (j = 0; j < n; j++) {
            int next = (i + j) % n;
            gas_left += gas[next] - cost[next];
            if (gas_left < 0)
                break;
        }
        if (j == n)
            return i;
        i += j + 1;
    }
    return -1;
}

int main() {
    
}
