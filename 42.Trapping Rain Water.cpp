#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int ret = 0, left = 0, right = height.size() - 1;
    while (left <= right) {
        if (height[left] < height[right]) {
            int i = left + 1, tmpRet = 0;
            while (i <= right && height[i] <= height[left]) {
                tmpRet += height[left] - height[i++];
            }
            ret += tmpRet;
            left = i;
        } else {
            int i = right - 1, tmpRet = 0;
            while (left <= i && height[i] <= height[right]) {
                tmpRet += height[right] - height[i--];
            }
            ret += tmpRet;
            right = i;
        }
    }
    return ret;
}

int main() {
	int a[] = {5,5,1,7,1,1,5,2,7,6};
	vector<int> v (a, a + sizeof(a) / sizeof(a[0]));
	cout << trap(v) << endl;
}