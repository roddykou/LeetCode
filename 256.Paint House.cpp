#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCost(vector<vector<int>>& costs) {
    // Write your code here
   int n = costs.size();
   if (n == 0)  return 0;
   vector<vector<int>> ret = vector<vector<int>> (n, vector<int> (3, 0));
   ret[0][0] = costs[0][0];
   ret[0][1] = costs[0][1];
   ret[0][2] = costs[0][2];
   for (int i = 1; i < n; i++) {
      ret[i][0] = costs[i][0] + min(ret[i - 1][1], ret[i - 1][2]);
      ret[i][1] = costs[i][1] + min(ret[i - 1][0], ret[i - 1][2]);
      ret[i][2] = costs[i][2] + min(ret[i - 1][0], ret[i - 1][1]);
   }
   return min(ret[n - 1][0], min(ret[n - 1][1], ret[n - 1][2]));
}

int main() {

}
