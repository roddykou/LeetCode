#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<string>>& ret, vector<string>& square, vector<string>& v, int n, int idx) {
	if (idx == n) {
		ret.push_back(square);
		return;
	} 

	for (int i = 0; i < v.size(); i++) {
		// if (v[i] != "#") {
			string str = v[i];
			bool valid = true;
			for (int j = 0; j < idx && valid; j++)
				if (str[j] != square[j][idx])
					valid = false;
			if (valid) {
				square[idx] = str;
				// v[i] = "#";
				dfs(ret, square, v, n, idx + 1);
				square[idx] = "";
				// v[i] = str;
			}
		// }
	}
}

// 20:28
vector<vector<string>> wordSquares(vector<string>& v) {
	vector<vector<string>> ret;
	if (v.empty())	return ret;

	int n = v[0].length();
	vector<string> square (n);
	dfs(ret, square, v, n, 0);
	return ret;
}

int main() {
	vector<string> v = {"area","lead","wall","lady","ball"};
	// vector<string> v = {"abat","baba","atan","atal"};
	vector<vector<string>> square = wordSquares(v);

	for (auto row : square) {
		for (auto str : row) {
			cout << str << ", ";
		}
		cout << endl;
	}
}