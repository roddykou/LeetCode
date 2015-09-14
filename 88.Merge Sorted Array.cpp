#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m + n - 1, j = m - 1, k = n - 1;
    while ( i >= 0) {
        if (j < 0)
            nums1[i--] = nums2[k--];
         if (k < 0 || nums1[j] > nums2[k])
            nums1[i--] = nums1[j--];
        else
            nums1[i--] = nums2[k--];
    }
}

int main () {
    cout << "Caution the edge case where one of the arrays has been traversed over" << endl;
}
