#include <vector>
#include <iostream>

using namespace std;

int maxProfit(vector<int>& prices) {
	int ret = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1])
			ret += prices[i] - prices[i - 1];
	}
	return ret;
}

int main() {
}
