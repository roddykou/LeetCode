#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int> >& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j  = 0; j < nums[i].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < nums.size() + nums[0].size() - 1; i++) {
		for (int row = 0; row <= i; row++) {
			if (row < nums.size() && i - row < nums[0].size()) {
				cout << nums[row][i - row] << " ";
			}
		}
		cout << ", ";
	}
}

int main() {
	int row1[] = {1, 2, 3, 4};
	int row2[] = {5, 6, 7, 8};
	int row3[] = {9, 10, 11, 12};

	vector<int> v1 (row1, row1 + sizeof(row1) / sizeof(int));
	vector<int> v2 (row2, row2 + sizeof(row2) / sizeof(int));
	vector<int> v3 (row3, row3 + sizeof(row3) / sizeof(int));

	vector<vector<int> > nums;
	nums.push_back(v1);
	nums.push_back(v2);
	nums.push_back(v3);

	print(nums);
	return 0;
}
