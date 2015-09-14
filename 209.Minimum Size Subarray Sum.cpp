#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int ret = INT_MAX, start = 0, end = 0, sum = 0;
    while (start < nums.size() && end < nums.size()) {
    	cout << "start " << start << " end " << end << " sum " << sum << endl;
    	if (sum < s) {
    		sum += nums[end];
    		if (sum < s)
    			end++;
    	} else {
    		ret = min(ret, end - start + 1);
    		sum -= nums[start++];
    		if (sum < s)
    			end++;
    	}
    }
    return ret == INT_MAX ? 0 : ret;
}

int main() {
	//		   0 1 2 3 4 5
	int a[] = {2,3,1,2,4,3};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << minSubArrayLen(7, v) << endl;
}