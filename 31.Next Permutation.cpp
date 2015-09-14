#include <vector>
#include <iostream>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1])     i--;
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int bigger = i + 1;
    while (bigger < nums.size() && nums[bigger] > nums[i])  bigger++;
    bigger--;

    swap(nums[i], nums[bigger]);
    reverse(nums.begin() + i + 1, nums.end());
    return;
}

int main() {
    int a[] = {1,2};
    vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
    nextPermutation(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ",";
    cout << endl;
}


/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4


*/
