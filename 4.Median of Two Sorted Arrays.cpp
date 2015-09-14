#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /* target is the number of int we wanna pass to achieve the (target + 1)th int */
    int ind1 = 0, ind2 = 0, target = (nums1.size() + nums2.size() - 1) / 2;
    int remain1 = nums1.size() - ind1, remain2 = nums2.size() - ind2;
    while (target > 0 && remain1 > 0 && remain2 > 0) {
        int step1 = 0, step2 = 0;
        if (remain1 < remain2) {
            step1 = min((target + 1) / 2, remain1);
            step2 = max(target - step1, 1);         /* avoid infinite loop when target == 1 */
        } else {
            step2 = min((target + 1) / 2, remain2);
            step1 = max(target - step2, 1);         /* avoid infinite loop when target == 1 */
        }

        /* don't compare nums1[ind1] & nums2[ind2] */
        if (nums1[ind1 + step1 - 1] < nums2[ind2 + step2 - 1]) {
            ind1 += step1;
            target -= step1;
            remain1 = nums1.size() - ind1;
        } else {
            ind2 += step2;
            target -= step2;
            remain2 = nums2.size() - ind2;
        }
    }
    if (remain1 == 0)   ind2 = (nums1.size() + nums2.size() - 1) / 2 - nums1.size();
    if (remain2 == 0)   ind1 = (nums1.size() + nums2.size() - 1) / 2 - nums2.size();
    if ((nums1.size() + nums2.size()) % 2 == 1) {
        /* don't put target == 0 at front */
        if (remain1 == 0)   return nums2[ind2];
        if (remain2 == 0)   return nums1[ind1];
        if (target == 0)    return min(nums1[ind1], nums2[ind2]);
        return -99;
    } else {
        if (remain1 == 0) {
            return ((double) (nums2[ind2] + nums2[ind2 + 1])) / 2;
        } else if (remain2 == 0) {
            return ((double) (nums1[ind1] + nums1[ind1 + 1])) / 2;
        } else if (target == 0) {
            if (nums1[ind1] < nums2[ind2]) {
                if (ind1 < nums1.size() - 1)
                    return ((double) (nums1[ind1] + min(nums1[ind1 + 1], nums2[ind2]))) / 2;
                else
                    return ((double) (nums1[ind1] + nums2[ind2])) / 2;
            } else {
                if (ind2 < nums2.size() - 1)
                    return ((double) (nums2[ind2] + min(nums2[ind2 + 1], nums1[ind1]))) / 2;
                else
                    return ((double) (nums1[ind1] + nums2[ind2])) / 2;
            }
        } else {
            return -99;
        }
    }
    return -99;
}

int main() {
    //         0 1 2 3  4   5  6  7
    int a[] = {};
    int b[] = {1,2,3,4};
    // int a[] = {1,3,5,7,9};
    // int b[] = {5,6,8,10,13,15,20,29};
    // int a[] = {1,2};
    // int b[] = {1,2,3};
    vector<int> v1 (a, a + sizeof(a) / sizeof(int));
    vector<int> v2 (b, b + sizeof(b) / sizeof(int));
    cout << findMedianSortedArrays(v1, v2) << endl;
}
