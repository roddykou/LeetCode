#include <iostream>
#include <vector>

using namespace std;

void contaminate(vector<vector<char> > &grid, int i, int j);

int numIslands(vector<vector<char> >& grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                ret++;
                contaminate(grid, i, j);
            }
        }
    }
    return ret;
}

void contaminate(vector<vector<char> > &grid, int i, int j){
    grid[i][j] = '0';
    if (i > 0 && grid[i - 1][j] == '1')
        contaminate(grid, i - 1, j);
    if (i < grid.size() - 1 && grid[i + 1][j] == '1')
        contaminate(grid, i + 1, j);
    if (j > 0 && grid[i][j - 1] == '1')
        contaminate(grid, i, j - 1);
    if (j < grid[0].size() - 1 && grid[i][j + 1] == '1')
        contaminate(grid, i, j + 1);
}

int main() {

}
