#include <iostream>
#include <vector>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    string tmp;
    if (nums.size() == 0)   return ret;

    int low = nums[0], high = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == high + 1) {
            high++;
        } else {
            tmp = to_string(low);
            if (high != low)
                tmp += "->" + to_string(high);
            ret.push_back(tmp);
            high = low = nums[i];
        }
    }

    if (high != low) {
        tmp = to_string(low) + "->" + to_string(high);
        ret.push_back(tmp);
    } else {
        tmp = to_string(low);
        ret.push_back(tmp);
    }

    return ret;
}

int main() {
}
