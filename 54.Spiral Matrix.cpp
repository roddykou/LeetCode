#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> ret;
    if (matrix.empty()) return ret;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, right = n - 1, bottom = m - 1, left = 0;
    while (top < bottom && left < right) {
        for (int i = left; i < right; i++)  ret.push_back(matrix[top][i]);
        for (int i = top; i < bottom; i++)  ret.push_back(matrix[i][right]);
        for (int i = right; i > left; i--)  ret.push_back(matrix[bottom][i]);
        for (int i = bottom; i > top; i--)  ret.push_back(matrix[i][left]);
        top++, right--, bottom--, left++;
    }
    if (top == bottom)
        for (int i = left; i <= right; i++)
            ret.push_back(matrix[top][i]);
    else if (left == right)
        for (int i = top; i <= bottom; i++)
            ret.push_back(matrix[i][left]);
    return ret;
}

int main () {

}
