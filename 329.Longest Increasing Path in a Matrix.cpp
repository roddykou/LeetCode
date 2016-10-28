#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int> >& matrix, vector<vector<int> >& dp,
        int i, int j, int m, int n) {
    if (dp[i][j] != 0)  return dp[i][j];
    int ret = 1;
    if (i > 0 && matrix[i - 1][j] > matrix[i][j])
        ret = max(ret, 1 + dfs(matrix, dp, i - 1, j, m, n));
    if (j > 0 && matrix[i][j - 1] > matrix[i][j])
        ret = max(ret, 1 + dfs(matrix, dp, i, j - 1, m, n));
    if (i < m - 1 && matrix[i + 1][j] > matrix[i][j])
        ret = max(ret, 1 + dfs(matrix, dp, i + 1, j, m, n));
    if (j < n - 1 && matrix[i][j + 1] > matrix[i][j])
        ret = max(ret, 1 + dfs(matrix, dp, i, j + 1, m, n));
    dp[i][j] = ret;
    return ret;
}

int longestIncreasingPath(vector<vector<int> >& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int> > dp (m, vector<int> (n, 0));

    int ret = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ret = max(ret, dfs(matrix, dp, i, j, m, n));
    return ret;
}

int main() {
   
}
