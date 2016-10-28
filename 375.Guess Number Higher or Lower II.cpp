#include <iostream>
#include <vector>

using namespace std;

/*
 The original problem can be interpreted as: using the best strategy to play the
 game in the worst case scenario.
 
 We need a 2D array maintain the answer for range (start to end). For each range,
 the player can have (start - end + 1) different choices and we need to choose
 the best among those choices. But for each choice we need to calculate as the
 worst case cuz we don't know where's the right answer (either half).

 We can think of an example where n = 3

getMoneyAmount(1) -> 0
getMoneyAmount(2) -> 1
getMoneyAmount(3) -> 2
 */
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int range = 2; range <= n; range++) {
        for (int start = 1; start + range - 1 <= n; start++) {
            int end = start + range - 1;
            int bestChoice = INT_MAX;
            for (int choose = start; choose <= end; choose++)
                bestChoice = min(bestChoice, choose + max(dp[start][choose - 1], dp[choose + 1][end]));
            dp[start][end] = bestChoice;
        }    
    }
    return dp[1][n];
}

int main() {

}