#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2)  return 0;
    vector<int> dp (n, 0);
    int buy = prices[0], profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] <= buy)
            buy = prices[i];
        else
            profit = max(profit, prices[i] - buy);
        dp[i] = profit;
    }

    profit = 0;
    int sell = prices[n - 1], ret = dp[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (prices[i] >= sell)
            sell = prices[i];
        else
            profit = max(profit, sell - prices[i]);
        ret = max(ret, dp[i] + profit);
    }

    return ret;
}

int main() {
}
