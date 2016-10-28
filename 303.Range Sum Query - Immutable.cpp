#include <iostream>
#include <vector>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums.push_back(0);
        int sum = 0;
        for (int num : nums) {
            sum += num;
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};

int main() {
    
}