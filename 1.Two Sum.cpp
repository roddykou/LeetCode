#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> ret (2, 0);
    for (int i = 0; i < nums.size(); i++) {
    	if (map.find(nums[i]) == map.end()) {
    		map[target - nums[i]] = i;
    	} else {
    		/* the answer is not zero-indexed */
    		ret[0] = map[nums[i]] + 1;
    		ret[1] = i + 1;
    	}
    }
    return ret;
}

int main() {
	int a[] = {2, 7, 11, 15};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	vector<int> result = twoSum(v, 9);
	cout << result[0] << ", " << result[1] << endl;
	return 0;
}