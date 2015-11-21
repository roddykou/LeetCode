#include <iostream>
#include <vector>

using namespace std;

struct bucket {
    int min, max;
    bucket () { min = INT_MAX; max = INT_MIN; }
};

int maximumGap(vector<int>& nums) {
    int n = nums.size(), maxi = INT_MIN, mini = INT_MAX;

    if (n < 2)  return 0;

    for ( int i : nums) {
        if (i > maxi)
            maxi = i;
        if (i < mini)
            mini = i;
    }

    /* case: 1, 1, 1, 5, 5, 5 */
    int bucketSize = max(1, (maxi - mini) / (n - 1));
    int numBuckets = 1 + ((maxi - mini) / bucketSize);
    vector<bucket> buckets (numBuckets);

    for ( int i : nums) {
        int bucketId = (i - mini) / bucketSize;
        if (i < buckets[bucketId].min)
            buckets[bucketId].min = i;
        if (i > buckets[bucketId].max)
            buckets[bucketId].max = i;
    }

    int ret = 0, preMax = mini;
    for (bucket b : buckets) {
        if (b.min != INT_MAX) {
            ret = max(ret, b.min - preMax);
            preMax = b.max;
        }
    }

    return ret;
}

int main() {

}
