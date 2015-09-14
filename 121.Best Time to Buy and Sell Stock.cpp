#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int ret = 0, buy = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < buy)
            buy = prices[i];
        else
            ret = max(ret, prices[i] - buy);
    }
    return ret;
}

int main() {

}
