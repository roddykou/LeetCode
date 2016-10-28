#include <iostream>
#include <vector>

using namespace std;

void printHeights(vector<int>& heights) {
	for (int height : heights) {
		for (int i = 0; i < height; i++)
			cout << "* ";
		cout << endl;
	}
	cout << endl;

	int maxH = 0;
	for (int h : heights)
		maxH = max(maxH, h);

	for (int i = maxH; i > 0; i--) {
		for (int h : heights)
			cout << (h < i ? " " : "*") << " ";
		cout << endl;
	}
}

int main() {
	vector<int> h = {2,4,5,7,4,2};
	printHeights(h);
}
