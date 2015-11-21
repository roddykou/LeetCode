#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ret, tmpRet;
    if (nums.empty())   return ret;

    vector<int> currentPerm(1, nums[0]);
    tmpRet.push_back(currentPerm);
    for (int i = 1; i < nums.size(); i++) {
        ret.clear();
        for (vector<int> prevPerm : tmpRet) {
            for (int j = 0; j <= prevPerm.size(); j++) {
                currentPerm = prevPerm;
                currentPerm.insert(currentPerm.begin() + j, nums[i]);
                ret.push_back(currentPerm);
            }
        }
        tmpRet = ret;
    }
    return tmpRet;
}

int main() {

}
