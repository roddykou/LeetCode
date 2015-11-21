#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void markBoundryOs(vector<vector<char>>& board, int row, int col);
void markInnerOsAndBoundryOsBack(vector<vector<char>>& board);

/* in this case, we should use BFS rather than DFS */
void solve(vector<vector<char>>& board) {
    if (board.empty())  return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        markBoundryOs(board, i, 0);
        markBoundryOs(board, i, n - 1);
    }
    for (int j = 1; j < n - 1; j++) {
        markBoundryOs(board, 0, j);
        markBoundryOs(board, m - 1, j);
    }

    markInnerOsAndBoundryOsBack(board);
}

void markBoundryOs(vector<vector<char>>& board, int row, int col) {
    if (board[row][col] != 'O') return;
    board[row][col] = 'V';
    queue<pair<int, int>> q;
    q.push(make_pair(row, col));
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i > 0 && board[i - 1][j] == 'O') {
            board[i - 1][j] = 'V';
            q.push(make_pair(i - 1, j));
        }
        if (i < board.size() - 1 && board[i + 1][j] == 'O') {
            board[i + 1][j] = 'V';
            q.push(make_pair(i + 1, j));
        }
        if (j > 0 && board[i][j - 1] == 'O') {
            board[i][j - 1] = 'V';
            q.push(make_pair(i, j - 1));
        }
        if (j < board[0].size() && board[i][j + 1] == 'O') {
            board[i][j + 1] = 'V';
            q.push(make_pair(i, j + 1));
        }
    }
}

void markInnerOsAndBoundryOsBack(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            if (board[i][j] == 'V') board[i][j] = 'O';
        }
    }
}

int main() {

}
