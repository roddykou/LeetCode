#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int zero = 0, two = nums.size() - 1;
    for (int i = 0; i <= two; i++) {
    	if (nums[i] == 0)
    		swap(nums[i], nums[zero++]);
    	else if (nums[i] == 2)
    		swap(nums[i--], nums[two--]);
    }
}

int main() {
	int a[] = {2,1,2,2,0,1,1,0,1,0,2,2,0,0,2};
	std::vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	sortColors(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;
}