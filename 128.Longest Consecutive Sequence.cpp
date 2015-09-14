#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    int ret = 0, left = 0, right = 0;
    for (int num : nums) {
    	/* This can not be map.find(num) == map.end() 
    	 * map[num + 1] may create fake entry */
        if (map[num] == 0) {
            left = map[num - 1], right = map[num + 1];
            int tmp = left + 1 + right;
            map[num] = map[num - left] = map[num + right] = tmp;
            ret = max(ret, tmp);
        }
    }
    return ret;
}

int main() {
	int a[] = {0, -1};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << longestConsecutive(v) << endl;
}