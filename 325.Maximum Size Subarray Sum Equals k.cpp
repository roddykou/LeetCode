#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k) {
    int sum = 0, ret = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum == k)
        	ret = i + 1;
        else if (map.find(sum - k) != map.end())
        	ret = max(ret, i - map[sum - k]);

        if (map.find(sum) == map.end())
        	map[sum] = i;
    }
    return ret;
}

int main () {
	// nums: [1, -1, 5, -2, 3], k = 3
	// sums: [1, 0, 5, 3, 6]
	// vector<int> v = {1, -1, 5, -2, 3};
	// cout << maxSubArrayLen(v, 3) << endl;

	// nums: [-2, -1, 2, 1], k = 1
	// sums: [-2, -3, -1, 0]
	// vector<int> v = {-2, -1, 2, 1};
	// cout << maxSubArrayLen(v, 1) << endl;

	// nums: [1, 0, -1], k = -1
	// sums: [1, 1, 0]
	vector<int> v = {1, 0, -1};
	cout << maxSubArrayLen(v, -1) << endl;
}