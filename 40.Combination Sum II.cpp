#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int> >& ret, vector<int>& comb, vector<int>& candidates, int index, int sum, int target) {
    if (sum == target) {
        ret.push_back(comb);
    } else if (sum < target) {
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
               continue;
            comb.push_back(candidates[i]);
            helper(ret, comb, candidates, i + 1, sum + candidates[i], target);
            comb.pop_back();
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ret;
    vector<int> comb;
    helper(ret, comb, candidates, 0, 0, target);
    return ret;
}

int main() {
    cout << "Only do Combination Sum III" << endl;
}
