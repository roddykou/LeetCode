#include <iostream>
#include <vector>

using namespace std;

//   0    1    2    3    4    5    6    7    8   9    10
// {'F', 'R', 'R', 'R', 'W', 'W', 'R', 'W', 'R','W', 'O'};
// input: F R R R R R W W R W O and velocity = 1
// output: true/false
bool jump(vector<char> pound, int velocity) {
	int n = pound.size();
	vector<vector<bool> > dp (n, vector<bool> (n, false));
	dp[0][velocity] = true;
	for (int i = 1; i < n; i++) {
		if (pound[i] == 'R' || pound[i] == 'O') {
			for (int j = 1; j < n; j++) {
				if (i - j >= 0)
					dp[i][j] = dp[i][j] || dp[i - j][j];
				if (i - j - 1 >= 0 && j + 1 < n)
					dp[i][j] = dp[i][j] || dp[i - j - 1][j + 1];
				if (i - j + 1 >= 0 && j - 1 < n)
					dp[i][j] = dp[i][j] || dp[i - j + 1][j - 1];
					// dp[i][j] = dp[i - j][j] || dp[i - j - 1][j + 1] || dp[i - j + 1][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	for (int j = 1; j < n; j++)
		if (dp[n - 1][j])
			return true;
	return false;
}

int main () {
	char pound_array[] = {'F', 'R', 'R', 'R', 'W', 'W', 'R', 'W', 'R', 'W', 'O'};
	vector<char> pound_vector (pound_array, pound_array + sizeof(pound_array) / sizeof(char));
	cout << jump(pound_vector, 1);
}