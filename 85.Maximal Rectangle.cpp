#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> >& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> height (m, 0);
    vector<int> left (m, 0), right (m, m - 1);
    int ret = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;

        for (int j = 1; j < m; j++) {
            int tmp = j;
            while (tmp > 0 && height[tmp - 1] >= height[j]) tmp = left[tmp  -1];
            left[j] = tmp;
        }

        for (int j = m - 2; j >= 0; j--) {
            int tmp = j;
            while (tmp < m - 1 && height[tmp + 1] >= height[j])  tmp = right[tmp + 1];
            right[j] = tmp;
        }

        for (int j = 0; j < m; j++)
            ret = max(ret, height[j] * (right[j] - left[j] + 1));
    }

    return ret;
}

int main() {
}
