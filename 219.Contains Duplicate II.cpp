#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    /* keeps a set containing up to k elements */
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++) {
        if (set.size() > k + 1) {
            cout << "fuck" << endl;
        } else if (set.size() == k + 1) {
            set.erase(nums[i - k - 1]);
        }
        /* can't put it into another else clause, should exe it anyway */
        if (set.find(nums[i]) != set.end()) return true;
        set.insert(nums[i]);
    }
    return false;
}

int main() {
	int a[] = {1, 0, 1, 1};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	cout << containsNearbyDuplicate(v, 1) << endl;
	return 0;
}

// [1,0,1,1], 1