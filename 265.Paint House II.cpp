#include <iostream>
#include <vector>

using namespace std;

int minCostII(vector<vector<int>>& costs) {
    // Write your code here
    int n = costs.size();       // number of houses
    if (n == 0) return 0;
    int k = costs[0].size();    // number of colors
    if (k == 0) return 0;
    
    int preMin = INT_MAX, preSecMin = INT_MAX, preMinIdx = -1;
    for (int i = 0; i < k; i++) {
        if (costs[0][i] < preMin) {
            preSecMin = preMin;
            preMin = costs[0][i];
            preMinIdx = i;
        } else if (costs[0][i] < preSecMin) {
            preSecMin = costs[0][i];
        }
    }
    
    for (int i = 1; i < n; i++) {
        int curMin = INT_MAX, curSecMin = INT_MAX, curMinIdx = -1;
        for (int j = 0; j < k; j++) {
            int curCost = 0;
            if (j == preMinIdx) {
                curCost = preSecMin + costs[i][j];
            } else {
                curCost = preMin + costs[i][j];
            }
            if (curCost < curMin) {
                curSecMin = curMin;
                curMin = curCost;
                curMinIdx = j;
            } else if (curCost < curSecMin) {
                curSecMin = curCost;
            }
        }
        preMin = curMin;
        preSecMin = curSecMin;
        preMinIdx = curMinIdx;
    }
    return preMin;
}

int main() {

}
