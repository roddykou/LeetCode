#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int ret = 0, prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
    	if (nums[i] != prev) {
    		prev = nums[i];
    		swap(nums[i], nums[++ret]);
    	}
    }
    return ret + 1;
}

int main() {
	int a[] = {1,1,2,3,3,3,4,5,5,5,5};
	std::vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	int newLen = removeDuplicates(v);
	for (int i = 0; i < newLen; i++) {
		cout << v[i] << ",";
	}
	cout << endl;
}