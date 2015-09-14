#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& height) {
    int size = height.size(), ret = 0;
    vector<int> left (size, 0), right (size, size - 1);
    for (int leftIndex = 1; leftIndex < size; leftIndex++) {
		int leftRunner = leftIndex;
		while (leftRunner > 0 && height[leftIndex] <= height[leftRunner - 1])
			leftRunner = left[leftRunner - 1];
		left[leftIndex] = leftRunner;

    	int rightIndex = size - leftIndex - 1;
    	int rightRunner = rightIndex;
    	while (rightRunner < size - 1 && height[rightIndex] <= height[rightRunner + 1])
    		rightRunner = right[rightRunner + 1];
    	right[rightIndex] = rightRunner;

    }

    for (int i = 0; i < size; i++)	ret = max(ret, (right[i] - left[i] + 1) * height[i]);
    return ret;
}

int main() {
	//	 	   0 1 2 3 4 5
	int a[] = {2,1,5,6,2,3};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << largestRectangleArea(v) << endl;
}

/*
	0 1 2 3 4 5
l   0 0 2 3 2 5
r   0 5 3 3	5 5	
*/