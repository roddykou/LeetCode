#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ret (1, vector<int> ());
    int i = 0;
    while (i < nums.size()) {
        int dup = 0, number = nums[i];
        while (i < nums.size() && nums[i] == number) {
            i++;
            dup++;
        }
        int prevSize = ret.size();
        for (int j = 0; j < prevSize; j++) {
            vector<int> prevSet = ret[j];
            for (int k = 0; k < dup; k++) {
                prevSet.push_back(number);
                ret.push_back(prevSet);
            }
        }

    }
    return ret;
}

int main() {
}
