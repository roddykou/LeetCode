#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> >& ret, vector<int>& current,
         int n, int k, int now) {
    for (int i = (now == 1 ? 1 : current[now - 2] + 1); i <= n - k + now; i++) {
        cout << i << endl;
        current.push_back(i);
        if (now == k)
            ret.push_back(current);
        else
            dfs(ret, current, n, k, now + 1);
        current.pop_back();
    }
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ret;
    vector<int> current;
    dfs(ret, current, n, k, 1);
    return ret;
}

int main() {

}
