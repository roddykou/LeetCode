#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int kSum(vector<int> A, int k, int target) {
	vector<vector<int>> ans (k + 1, vector<int> (target + 1, 0));
	ans[0][0] = 1;
    for(int i = 0; i < A.size(); ++i) {
    	// interate j in descending order, avoid duplicate calcultion at
    	// ans[j]... += ans[j - 1]... for the same A[i].
        for(int j = k; j > 0; j--) {
        	for (int m = A[i]; m <= target; m++) {
                ans[j][m] += ans[j - 1][m - A[i]];
                if(ans[j][m] > 2147483647)
                    return -1;
            }
        }
    }

    // for (int i = 0; i < ans.size(); i++) {
    // 	for (int j = 0; j < ans[0].size(); j++) {
    // 		cout << ans[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }

    return ans[k][target];
}

int main () {
	int a[] = {1,2,3,4};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	cout << kSum(v, 2, 5) << endl;
}