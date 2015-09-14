#include <iostream>
#include <vector>

using namespace std;

bool valid(int i, int j, int number, bool row[][9], bool col[][9], bool grid[][9]) {
    return !row[i][number] && !col[j][number] && !grid[i / 3 * 3 + j / 3][number];
}

bool solve(int i, int j, vector<vector<char> >& board,
           bool row[][9], bool col[][9], bool grid[][9]) {
    if (i >= 9) {
        return true;
    } else if (j >= 9) {
        return solve(i + 1, 0, board, row, col, grid);
    } else {
        if (board[i][j] == '.') {
            for (int number = 0; number < 9; number++) {
                if (valid(i, j, number, row, col, grid)) {
                    row[i][number] = col[j][number] = grid[i / 3 * 3 + j / 3][number] = true;
                    board[i][j] = '1' + number;
                    if (!solve(i, j+ 1, board, row, col, grid)) {
                        row[i][number] = col[j][number] = grid[i / 3 * 3 + j / 3][number] = false;
                        board[i][j] = '.';
                    } else {
                        return true;
                    }
                }
            }
            return false;
        } else {
            return solve(i, j + 1, board, row, col, grid);
        }
    }

}

void solveSudoku(vector<vector<char> >& board) {
    bool row[9][9] = {false}, col[9][9] = {false}, grid[9][9] = {false};
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int number = board[i][j] - '1';
                row[i][number] = col[j][number] = grid[i /3 * 3 + j / 3][number] = true;
            }
        }
    }
    solve(0, 0, board, row, col, grid);
}

int main() {
}
