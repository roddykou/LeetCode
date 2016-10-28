#include <vector>
#include <iostream>

using namespace std;

/*

                    +-----------+             +-----------+
              +-----+           |     cool    |           |
         cool |     | COOLDOWN  | <-----------+   SELL    |
              +---->|           |             |           |
                    +-----------+             +-----------+
                           |                       ^
                           |                       |
                           |buy                    |sell
                           |                       |
                           |    +-----------+      |
                           +--> |           +------+
                                |    BUY    |
                                |           |
                                +-----------+
                                  |       ^
                                  |       |
                                  |  cool |
                                  +-------+

 */

int maxProfit(vector<int> &prices) {
	int n = prices.size();
	if (n < 2)	return 0;
	vector<int> buy (n), sell (n), cool (n);
	buy[0] = -prices[0];
	for (int i = 1; i < n; i++) {
		buy[i] = max(buy[i  -1], cool[i - 1] - prices[i]);
		sell[i] = buy[i - 1] + prices[i];
		cool[i] = max(sell[i  -1], cool[i  -1]);
	}
	return max(buy[n - 1], max(sell[n - 1], cool[n - 1]));
}

int maxProfitLessSpace(vector<int>& prices) {
	int sold = 0, hold = INT_MIN, cool = 0;
	for (int n : prices) {
		int prevSold = sold;
		sold = hold + n;
		hold = max(hold, cool - n);
		cool = max(cool, prevSold);
	}
	return max(sold, cool);
}

int main() {
	vector<int> v = {1, 2, 3, 0, 2};
	cout << maxProfit(v) << endl;
	cout << maxProfitLessSpace(v) << endl;
}