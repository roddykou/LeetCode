#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    if (nums.size() == 1)   return 0;
    int ret = 0, curFrom = 0, curTo = 0;
    while (curTo < nums.size() - 1) {
        ret++;
        int nextReach = 0;
        for (int i = curFrom; i <= curTo; i++) {
            nextReach = max(nextReach, i + nums[i]);
        }
        if (nextReach <= curTo)
            return 0;
        curFrom = curTo + 1;
        curTo = nextReach;
    }
    return ret;
}

int main () {

}
