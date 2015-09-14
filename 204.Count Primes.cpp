#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* 0 & 1 are not prime numbers */
int countPrimes(int n) {
    if (n <= 2)  return 1;
    int ret = 0;
    vector<bool> isPrime (n, true);
    
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            ret++;
            /* avoid overflow */
            if (i > sqrt(INT_MAX))  continue;
            for (long j = i * i; j < n && j >= 0; j += i) {
                isPrime[j] = false;
            }
        }    
    }
    return ret;
}

int main() {
    cout << countPrimes(499979) << endl;
}