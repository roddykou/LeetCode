#include <iostream>
#include <vector>

using namespace std;

/*
		A	B	C 	D
week1 	2	1	1	0
week2 	0 	1	1	0
week3 	3	0	1	2

*/

int getMaxVacation(vector<vector<int>>& v) {
	vector<vector<int>> dp (v.size(), vector<int> (v[0].size(), 0));
	dp[v.size() - 1] = v[v.size() - 1];

	for (int i = v.size() - 2; i >= 0; i--) {
		for (int j = 0; j < v[0].size(); j++) {
			int maxNext = INT_MIN;
			for (int k = 0; k < v[0].size(); k++) {
				maxNext = max(maxNext, dp[i + 1][k]);
			}
			dp[i][j] = v[i][j] + maxNext;
		}
	}

	int ret = INT_MIN;
	for (int j = 0; j < dp[0].size(); j++)
		ret = max(ret, dp[0][j]);
	return ret;
}

int main() {
	vector<int> week1;
	week1.push_back(2);
	week1.push_back(1);
	week1.push_back(1);
	week1.push_back(0);

	vector<int> week2;
	week2.push_back(0);
	week2.push_back(1);
	week2.push_back(1);
	week2.push_back(0);

	vector<int> week3;
	week3.push_back(3);
	week3.push_back(0);
	week3.push_back(1);
	week3.push_back(2);

	vector<vector<int>> v;
	v.push_back(week1);
	v.push_back(week2);
	v.push_back(week3);

	cout << getMaxVacation(v) << endl;
}