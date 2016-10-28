#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getBestResult(vector<int>& v, int start, int end, bool firstMove) {
	if (start == end)
		return firstMove ? make_pair(v[start], 0) : make_pair(0, v[start]);

	pair<int, int> r1 = getBestResult(v, start + 1, end, !firstMove);
	pair<int, int> r2 = getBestResult(v, start, end - 1, !firstMove);

	if (firstMove) {
		int diff1 = v[start] + r1.first - r1.second;
		int diff2 = v[end] + r2.first - r2.second;
		return diff1 > diff2 ? make_pair(r1.first + v[start], r1.second)
							 : make_pair(r2.first + v[end], r2.second);
	} else {
		int diff1 = r1.first - r1.second - v[start];
		int diff2 = r2.first - r2.second - v[end];
		return diff1 < diff2 ? make_pair(r1.first, r1.second + v[start])
							 : make_pair(r2.first, r2.second + v[end]);
	}
}

pair<int, int> getBestResultDp(vector<int>& v) {
	int n = v.size();
	bool firstMove = n % 2 == 1;	// indicating who perform the current pick up
	vector<vector<pair<int, int>>> dp (n, vector<pair<int, int>> (n));

	for (int i = 0; i < n; i++)
		dp[i][i] = firstMove ? make_pair(v[i], 0) : make_pair(0, v[i]);
	firstMove = !firstMove;

	for (int length = 1; length < n; length++) {
		for (int start = 0; start + length < n; start++) {
			int end = start + length;
			// plan 1 picks start, plan 2 picks end
			pair<int, int> r1 = dp[start + 1][end];
			pair<int, int> r2 = dp[start][end - 1];
			if (firstMove) {
				int diff1 = v[start] + r1.first - r1.second;
				int diff2 = v[end] + r2.first - r2.second;
				dp[start][end] = diff1 > diff2 ? make_pair(r1.first + v[start], r1.second)
											   : make_pair(r2.first + v[end], r2.second);
			} else {
				int diff1 = r1.first - r1.second - v[start];
				int diff2 = r2.first - r2.second - v[end];
				dp[start][end] = diff1 < diff2 ? make_pair(r1.first, r1.second + v[start])
											   : make_pair(r2.first, r2.second + v[end]);
			}
			cout << "dp[" << start << "][" << end << "] = " << dp[start][end].first << " " << dp[start][end].second << endl;
		}
		firstMove = !firstMove;
	}
	return dp[0][n - 1];
}

int main() {
	vector<int> v = {3, 9, 1 ,2};
	// vector<int> v = {1, 5, 3, 8, 10};
	// pair<int, int> r = getBestResult(v, 0, v.size() - 1, true);
	pair<int, int> r = getBestResultDp(v);
	cout << "winning with " << r.first << " vs " << r.second << endl;
}