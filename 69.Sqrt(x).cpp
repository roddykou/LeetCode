#include <cmath>
#include <iostream>

using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0;
    long ret = 1, tmp = x;
    while (abs(tmp - ret) > 1) {
        ret = (ret + tmp) / 2;
        tmp = x / ret;
    }
    return min(ret, tmp);
}

int main() {
   cout << mySqrt(25) << endl;
}
