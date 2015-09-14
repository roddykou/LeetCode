#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int> > &ret, vector<int> comb, vector<int> &candidates, int target, int sum, int ii) {
    if (sum == target) {
        ret.push_back(comb);
    } else if (sum < target) {
        for (int i = ii; i < candidates.size(); i++) {
            if (sum + candidates[i] > target)
                return;
            comb.push_back(candidates[i]);
            helper(ret, comb, candidates, target, sum + candidates[i], i);
            comb.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ret;
    vector<int> comb;
    helper(ret, comb, candidates, target, 0, 0);
    return ret;
}

int main() {
    cout << "Only do Combination Sum III" << endl;
}
