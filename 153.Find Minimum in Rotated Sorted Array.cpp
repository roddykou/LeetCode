#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
    while (start < end) {
    	if (nums[mid] < nums[end]) {
    		end = mid;
    	} else if (nums[mid] > nums[end]) {
    		start = mid + 1;
    	} else {
    		cout << "FUCK" << endl;
    	}
    	mid = (start + end)  / 2;
    }
    return nums[start];
}

int main () {
	int a[] = {4, 5, 6, 7, 0, 1, 2};
	std::vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << findMin(v) << endl;
}