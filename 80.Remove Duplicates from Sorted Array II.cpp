#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int ret = 1, prev = nums[0], app = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == prev) {
			if (app == 1) {
				app = 2;
				swap(nums[i], nums[ret++]);
			}
		} else {
			prev = nums[i];
			app = 1;
			swap(nums[i], nums[ret++]);
		}
	}
	return ret;
}

int main() {
	int a[] = {1,1,1,1,3,4,5,5,6,7,8,8,8,8,8};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	int newLen = removeDuplicates(v);
	for (int i = 0; i < newLen; i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}