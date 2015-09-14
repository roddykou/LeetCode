#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int ret1 = 0, ret2 = 0;
    int count1 = 0, count2 =0;
    for (int i = 0; i < n; i++) {
        if (count1 == 0) {
            ret1 = nums[i];
            count1 = 1;
        } else if (nums[i] == ret1) {
            count1++;
        } else if (count2 == 0) {
            ret2 = nums[i];
            count2 = 1;
        } else if (nums[i] == ret2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] == ret1)
            count1++;
        else if (nums[i] == ret2)
            count2++;

    vector<int> ret;
    if (count1 > n / 3)  ret.push_back(ret1);
    if (count2 > n / 3)  ret.push_back(ret2);
    return ret;
}

int main() {
    int a[] = {1,1,1,3,3,2,2,2};
    vector<int> v (a, a + sizeof(a) / sizeof(int));
    vector<int> result = majorityElement(v);
    cout << result[0] << ", " << result[1] << endl;
}
