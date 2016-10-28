#include <iostream>
#include <vector>

using namespace std;

pair<int, int> bestResult(vector<int>& v) {
	int n = v.size();
	vector<vector<pair<int, int>>> dp (n, vector<pair<int, int>> (n));
	bool firstPlayerPick = n % 2 == 1;
	for (int i = 0; i < n; i++)
		if (firstPlayerPick)
			dp[i][i] = {v[i], 0};
		else
			dp[i][i] = {0, v[i]};

	firstPlayerPick = !firstPlayerPick;
	for (int length = 2; length <= n; length++) {
		for (int start = 0; start + length - 1 < n; start++) {
			int end = start + length - 1;
			if (firstPlayerPick) {
				int diffPickStart = v[start] + dp[start + 1][end].first - dp[start + 1][end].second;
				int diffPickEnd = v[end] + dp[start][end - 1].first - dp[start][end - 1].second;
				if (diffPickStart > diffPickEnd)
					dp[start][end] = {v[start] + dp[start + 1][end].first, dp[start + 1][end].second};
				else
					dp[start][end] = {v[end] + dp[start][end - 1].first, dp[start][end - 1].second};
			} else {
				int diffPickStart = v[start] + dp[start + 1][end].second - dp[start + 1][end].first;
				int diffPickEnd = v[end] + dp[start][end - 1].second - dp[start][end - 1].first;
				if (diffPickStart > diffPickEnd)
					dp[start][end] = {dp[start + 1][end].first, dp[start + 1][end].second + v[start]};
				else
					dp[start][end] = {dp[start][end - 1].first, dp[start][end - 1].second + v[end]};
			}
		}
		firstPlayerPick = !firstPlayerPick;
	}
 
	return dp[0][n - 1];
}

int main() {
	vector<int> v = {3, 9, 1, 2};
	pair<int, int> ret = bestResult(v);
	cout << ret.first << " vs " << ret.second << endl;
}