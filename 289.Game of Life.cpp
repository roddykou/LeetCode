#include <vector>

using namespace std;

void gameOfLife(vector<vector<int> >& board) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            int count = -(board[i][j] & 0x1);
            for (int ii = max(0, i - 1); ii <= min(m - 1, i + 1); ii++) {
                for (int jj = max(0, j - 1); jj <= min(n - 1, j + 1); jj++) {
                    count += (board[ii][jj] & 0x1);
                }
            }
            if ((count == 2 && (board[i][j] & 0x1) == 0x1) || count == 3)
                board[i][j] |= 0x2;
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            board[i][j] >>= 1;
        }
    }
}

int main() {

}
