#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char> >& board) {
    bool row[9][9] = {false}, col[9][9] = {false}, grid[9][9] = {false};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int number = board[i][j] - '1';
                if (row[i][number] || col[j][number] ||
                    grid[i / 3 * 3 + j /3][number])
                    return false;
                row[i][number] = col[j][number] = grid[i / 3 * 3 + j /3][number] = true;
            }
        }
    }
    return true;
}

int main() {
}
