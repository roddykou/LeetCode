#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int ret = nums[0], tmp = 0;
    for (int i = 0; i < nums.size(); i++) {
    	tmp += nums[i];
    	ret = max(ret, tmp);
    	if (tmp < 0)	tmp = 0;
    }
    return ret;
}

int main() {
	// int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	// int a[] = {-2, 1};
	// int a[] = {-1};
	int a[] = {-2,-1,-2};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << maxSubArray(v) << endl;
}