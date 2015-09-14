#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool isRowOneZero = false;
    for (int j = 0; j < col; j++) {
        if (matrix[0][j] == 0)
            isRowOneZero = true;
    }

    for (int i = 1; i < row; i++) {
        bool thisRowZero = false;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                thisRowZero = true;
                matrix[0][j] = 0;
            }
        }
        if (thisRowZero) {
            for (int j = 0; j < col; j++)
                matrix[i][j] = 0;
        }
    }

    for (int j = 0; j < col; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < row; i++)
                matrix[i][j] = 0;
        }
    }

    if (isRowOneZero) {
        for (int j = 0; j < col; j++) {
            matrix[0][j] = 0;
        }
    }
}

int main() {
}
