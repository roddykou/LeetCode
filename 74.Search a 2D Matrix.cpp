#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int start = 0, end = row - 1, mid = (start + end) / 2;
    while (start < end - 1) {
        if (matrix[mid][0] < target)
            start = mid;
        else if (matrix[mid][0] > target)
            end = mid;
        else
            return true;
        mid = (start + end) / 2;
    }

    /* IMPORTANT */
    row = matrix[end][0] > target ? start : end;
    start = 0, end = col - 1, mid = (start + end) / 2;
    while (start <= end) {
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
        mid = (start + end) / 2;
    }
    return false;
}

int main() {
}
