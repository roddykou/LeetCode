#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int start = 0, end = height.size() - 1, ret = 0;
    while (start < end) {
        int startHeight = height[start], endHeight = height[end];            
        ret = max(ret, min(startHeight, endHeight) * (end - start));
        if (endHeight > startHeight)
            while (start < end && height[start] <= startHeight) 
                start++;
        else
            while (start < end && height[end] <= endHeight)
                end--;
    }
    return ret;
}

int main() {
	// int a[] = {1,2,4,3};
	int a[] = {5,2,12,1,5,3,4,11,9,4};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << maxArea(v) << endl;
}