#include <vector>
#include <iostream>

using namespace std;

int majorityElement(vector<int>& nums) {
    int ret = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
    	if (nums[i] != ret) {
    		count--;
    	} else {
    	    count++;
    	}
    	if (count == 0) {
    		ret = nums[i];
    		count = 1;
    	}
    }
    return ret;  
}

int main() {
	int a[] = {3,2,3};
	// int a[] = {3,3,4};
	vector<int> v (a, a + sizeof(a)/ sizeof(a[0]));
	cout << majorityElement(v) << endl;
	return 0;
}