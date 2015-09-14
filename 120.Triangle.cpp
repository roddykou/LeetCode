#include <vector>
#include <iostream>

using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    vector<int> minRow  = triangle[triangle.size() - 1];
    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            minRow[j] = triangle[i][j] + min(minRow[j], minRow[j + 1]);
    return minRow[0];
}

int main () {
}
