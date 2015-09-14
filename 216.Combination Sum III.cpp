#include <iostream>
#include <vector>

using namespace std;
void dfs (vector<vector<int> >& ret, vector<int>& row, int rowsum, int k, int n) {
    if (row.size() == k && rowsum == n)
        ret.push_back(row);
    else {
        for (int i = row.back() + 1; i < 10; i++) {
            row.push_back(i);
            dfs(ret, row, rowsum + i, k, n);
            row.pop_back();
        }
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > ret;
    vector<int> row;
    for (int i = 1; i < 10; i++) {
        row.push_back(i);
        dfs(ret, row, i, k, n);
        row.pop_back();
    }
    return ret;
}

int main () {
    vector<vector<int> > result = combinationSum3(3, 9);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << ",";
        cout << endl;
    }
}
