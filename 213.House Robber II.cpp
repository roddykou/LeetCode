#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1)
        return nums[0];

    int p1 = 0, pp1 = 0;
    for (int i = 0; i < n - 1; i++) {
        pp1 = max(pp1 + nums[i], p1);
        swap(p1, pp1);
    }

    int p2 = 0, pp2 = 0;
    for (int i = 1; i < n; i++) {
        pp2 = max(pp2 + nums[i], p2);
        swap(p2, pp2);
    }
    return max(p1, p2);
}

int main() {

}
