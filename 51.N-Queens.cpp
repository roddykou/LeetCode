#include <iostream>
#include <vector>

using namespace std;

void addResult(vector<vector<string> >& ret, vector<int>& table, int n) {
    vector<string> result (n, string (n, '.'));
    for (int i = 0; i < n; i++)
        result[i][table[i]] = 'Q';
    ret.push_back(result);
}

bool valid(vector<int>& table, int currentRow) {
    for (int i = 0; i < currentRow; i++) {
        if (table[i] == table[currentRow] ||
            table[i] + i == table[currentRow] + currentRow ||
            table[i] - i == table[currentRow] - currentRow)
            return false;
    }
    return true;
}

void dfs(vector<vector<string> >& ret, vector<int>& table, int row, int n) {
    for (int j = 0; j < n; j++) {
        table[row] = j;
        if (valid(table, row)) {
            if (row == n - 1)
                addResult(ret, table, n);
            else
                dfs(ret, table, row + 1, n);
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ret;
    if (n == 0) return ret;
    vector<int> table (n, -1);
    dfs(ret, table, 0, n);
    return ret;
}

int main() {
    
}
