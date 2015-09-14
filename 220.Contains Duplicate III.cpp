#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    /* Sets are typically implemented as binary search trees. */
	set<long> window;
    for (int i = 0; i < nums.size(); i++) {
        if (window.size() > k)
            window.erase(nums[i - k - 1]);
        set<long>::iterator itr = window.lower_bound((long)nums[i] - (long)t);
        if (itr != window.end() && *itr <= (long)nums[i] + (long)t)
            return true;
        window.insert(nums[i]);
    }
    return false;
}

int main() {
    int a[] = {1, 30, 3, 31};
    vector<int> v (a, a + sizeof(a) / sizeof(int));
    cout << containsNearbyAlmostDuplicate(v, 2, 1) << endl;
    return 0;
}