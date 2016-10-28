#include <iostream>
#include <vector>

using namespace std;

void previousBiggerNumber(vector<int>& v) {
	int n = v.size();
	vector<int> biggerNumber (n, 0), biggerIdx (n, 0);
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		while (j > 0 && v[j] <= v[i])
			j = biggerIdx[j];
		biggerIdx[i] = (j == 0 && v[0] < v[i]) ? i : j;
	}

	for (int i = 0; i < n; i++)
		biggerNumber[i] = v[biggerIdx[i]];

	// Print result
	for (int i : biggerNumber)	
		cout << i << " ";
	cout << endl;
}

int main() {
	int a[] = {9, 8, 7, 8, 4, 3, 10, 9};
	vector<int> v (a, a + sizeof(a) / sizeof(int));
	previousBiggerNumber(v);
}