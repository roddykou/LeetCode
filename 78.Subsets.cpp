#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > ret;
    vector<int> tmp;
    sort(S.begin(), S.end());
    for (int mask = 0; mask < (1 << S.size()); mask++) {
        for (int i = 0; i < S.size(); i++){
            if (mask & (1 << i)) {
                tmp.push_back(S[i]);
            }
        }
        ret.push_back(tmp);
        tmp.clear();
    }
    return ret;
}

int main() {
}
