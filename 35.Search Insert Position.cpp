#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int start = 0, end = nums.size() - 1, mid = (start + end) / 2;
	/* less or equals to not less */
	while (start <= end) {
		if (nums[mid] == target) {
			break;
		} else if (nums[mid] > target) {
			if (mid == 0 || target > nums[mid - 1]) {
				break;
			} else {
				end = mid;
			}
		} else {
			if (mid == nums.size()) {
				break;
			} else if (mid == nums.size() - 1 || nums[mid + 1] >= target) {
				mid++;
				break;
			} else {
				/* start != mid, will run int infinite loop when start == end - 1 */
				start = mid + 1;
			}
		}
		/* compute mid at the end not at start of the loop */
		mid = (start + end) / 2;
	}
    return mid;
}

// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0
int main() {
	int a[] = {1,3,5,6};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < 8; i++) {
		cout << "[1,3,5,6], " << i << " → " << searchInsert(v, i) << endl;
	}
	return 0;
 }