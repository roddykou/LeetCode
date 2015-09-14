#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > ret;
	if (numRows == 0)	return ret;
	vector<int> row (1, 1);
	ret.push_back(row);
	for (int i = 1; i < numRows; i++) {
		row.push_back(1);
		for (int j = 1; j < i; j++) {
			row[j] += ret[i - 1][j - 1];
		}
		ret.push_back(row);
	}
	return ret;
}

int main() {
	vector<vector<int> > result = generate(5);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
}

/*
1
1，1
1，2，1
1，3，3，1
1，4，6，4，1

*/