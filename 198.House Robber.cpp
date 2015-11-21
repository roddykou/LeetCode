#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int p = 0, pp = 0;
    for (int i : nums) {
        pp = max(pp + i, p);
        swap(p, pp);
    }
    return p;
}

int main() {

}
