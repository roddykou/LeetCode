#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//      2, 1, 5, 6, 2, 3
// l    0, 0, 2, 3, 2, 4
// r    0, 5, 3, 3, 5, 5
int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    vector<int> left (len, 0);
    for (int i = 1; i < len; i++) {
        int leftMost = i;
        while (leftMost > 0 && heights[leftMost - 1] >= heights[i])
            leftMost = left[leftMost - 1];
        left[i] = leftMost;
    }

    vector<int> right (len, len - 1);
    for (int i = len - 2; i >= 0; i--) {
        int rightMost = i;
        while (rightMost < len - 1 && heights[rightMost + 1] >= heights[i])
            rightMost = right[rightMost + 1];
        right[i] = rightMost;
    }

    int ret = 0;
    for (int i = 0; i < len; i++)
        ret = max(ret, heights[i] * (right[i] - left[i] + 1));
    return ret;
}

// int largestRectangleArea(vector<int>& height) {
//     int size = height.size(), ret = 0;
//     vector<int> left (size, 0), right (size, size - 1);
//     for (int leftIndex = 1; leftIndex < size; leftIndex++) {
// 		int leftRunner = leftIndex;
// 		while (leftRunner > 0 && height[leftIndex] <= height[leftRunner - 1])
// 			leftRunner = left[leftRunner - 1];
// 		left[leftIndex] = leftRunner;
//
//     	int rightIndex = size - leftIndex - 1;
//     	int rightRunner = rightIndex;
//     	while (rightRunner < size - 1 && height[rightIndex] <= height[rightRunner + 1])
//     		rightRunner = right[rightRunner + 1];
//     	right[rightIndex] = rightRunner;
//
//     }
//
//     for (int i = 0; i < size; i++)	ret = max(ret, (right[i] - left[i] + 1) * height[i]);
//     return ret;
// }

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
