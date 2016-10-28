#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> findStrobogrammatic(int n) {
	vector<vector<string>> ret (n + 1, vector<string> ());
	ret[0] = {""};
	ret[1] = {"0", "1", "8"};
	for (int i = 2; i <= n; i++) {
		for (string middle : ret[i - 2]) {
			ret[i].push_back("1" + middle + "1");
			ret[i].push_back("6" + middle + "9");
			ret[i].push_back("8" + middle + "8");
			ret[i].push_back("9" + middle + "6");
		}
	}
	return ret;
}

int main() {
	vector<vector<string>> result = findStrobogrammatic(4);
	for (int i = 0; i < result.size(); i++) {
		cout << "n = " << i << ": ";
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ", ";
		}
		cout << endl;
	}
}