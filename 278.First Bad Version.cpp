#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
   return rand() % 2 == 1;
}

int firstBadVersion(int n) {
    int lastGood = 1, firstBad = n, mid = lastGood + (firstBad - lastGood) / 2;
    while (lastGood < firstBad) {
        if (isBadVersion(mid)) {
            firstBad = mid;
        } else {
            lastGood = mid + 1;
        }
        mid = lastGood + (firstBad - lastGood) / 2;
    }
    return firstBad;
}

int main() {
   srand (time(nullptr));
   // cout << isBadVersion(1) << endl;
}
