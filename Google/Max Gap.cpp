#include <iostream>
#include <vector>

using namespace std;


// Given an unsorted array, for all a[i] <= a[j], find the maximum j - i
// O(N) time O(N) Space
int maxGap(vector<int>& v) {
	int n = v.size();
	vector<int> smallestSoFar (n, 0);

	int smallest = INT_MAX;
	for (int i : v) {
		smallest = min(smallest, i);
		smallestSoFar.push_back(smallest);
	}

	int ret = 0;
	for (int i = n - 1; i >= 0; i--) {
		while ((i - ret - 1) >= 0 && smallestSoFar[i - ret - 1] <= v[i])
			ret++;
	}

	return ret;
}

int main() {
	int a[] = {6, 2, 3, 4, 3, 5, 6};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	cout << maxGap(v) << endl;
}