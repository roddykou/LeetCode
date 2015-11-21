#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int row = dungeon.size(), col = dungeon[0].size();
    vector<vector<int> > dp (row, vector<int> (col, 0));
    dp[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
    for (int i = row - 2; i >= 0; i--)
        dp[i][col - 1] = max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
    for (int j = col - 2; j >= 0; j--)
        dp[row - 1][j] = max(1, dp[row - 1][j + 1] - dungeon[row - 1][j]);
    for (int i = row - 2; i >= 0; i--) {
        for (int j = col - 2; j >= 0; j--) {
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    return dp[0][0];
}

int main() {

}
