#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ret (nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
    	ret[i] = ret[i - 1] * nums[i - 1];
    }

    int tmp = 1;
    for (int i = nums.size() - 2; i >=0; i--) {
    	tmp *= nums[i + 1];
    	ret[i] *= tmp;
    }
    return ret;
}

int main() {
	int a[] = {1,2,3,4};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	vector<int> result = productExceptSelf(v);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ", ";
	cout << endl;
}