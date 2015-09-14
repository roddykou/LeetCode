#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int ret = nums.size();
    for (int i = 0; i < nums.size(); i++)
        ret ^= nums[i] ^ i;
    return ret;
}

int main() {
	cout << "Smarting Shit" << endl;
}

/*
	0-7
	0000
	0001
	0010
	0011
	0100
	0101
	0110
	0111
*/