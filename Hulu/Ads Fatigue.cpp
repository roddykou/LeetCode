#include <iostream>
#include <vector>

using namespace std;

// 就是比如3个slot _ _ _ gap是1
// 你可以这么放
// x _ x
// x _ _
// _ x _
// _ _ x
// _ _ _
// 一共5种

// x _ x _ x
// x _ x _ _
// x _ _ x _
// x _ _ _ x
// x _ _ _ _
// _ x _ x _
// _ x _ _ x
// _ x _ _ _
// ...

// x _ _ x _
// x _ _ _ x
// x _ _ _ _
// _ x _ _ x
// _ x _ _ _
// _ _ x _ _
// _ _ _ x _
// _ _ _ _ x
// _ _ _ _ _

void dfs(const int numSlots, const int gap, int position, int& ret) {
	// cout << "position " << position << " here!" << endl;
	if (position >= numSlots) {
		ret++;
	} else {
		int i = position + gap + 1;
		do {
			dfs(numSlots, gap, i, ret);
			i++;
		} while (i <= numSlots);
	}
}

int numOfAds(int numSlots, int gap) {
	int ret = 0;
	for (int i = 0; i <= numSlots; i++) {
		dfs(numSlots, gap, i, ret);
		// cout << ret << " solutions when starting from " << i << endl;
	}
	return ret;
}

int numOfAdsDp(int numSlots, int gap) {
	vector<int> dp (numSlots, 1);
	for (int i = 1; i < numSlots; i++)
		for (int j = 0; j < i - gap; j++)
			dp[i] += dp[j];

	int ret = 1;
	for (int i : dp)
		ret += i;
	return ret;
}

int main() {
	cout << numOfAds(3, 1) << endl;
	cout << numOfAds(5, 1) << endl;
	cout << numOfAds(5, 2) << endl;
	cout << numOfAdsDp(3, 1) << endl;
	cout << numOfAdsDp(5, 1) << endl;
	cout << numOfAdsDp(5, 2) << endl;
}