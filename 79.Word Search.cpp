#include <iostream>
#include <vector>

using namespace std;

bool helper(vector<vector<char> >& board, string& word, int x, int y, int i) {
    if (i == word.size())   return true;
    int m = board.size(), n = board[0].size();
    if (x < 0 || x >= m || y < 0 || y >= n || word[i] != board[x][y])   return false;
    char tmp = board[x][y];
    board[x][y] = '0';
    bool ret = helper(board, word, x - 1, y, i + 1) ||
               helper(board, word, x + 1, y, i + 1) ||
               helper(board, word, x, y - 1, i + 1) ||
               helper(board, word, x, y + 1, i + 1);
    board[x][y] = tmp;
    return ret;
}

bool exist(vector<vector<char> >& board, string word) {
    int m = board.size();
    if (m == 0) return false;
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (helper(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
}
