#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
        ret ^= nums[i];
    }
    return ret;
}

int main() {
	cout << "Hello Single Number" << endl;
}
