#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0)  return false;

    int rev = 0, org = x;
    while (org / 10) {
        rev = rev * 10 + org % 10;
        org /= 10;
    }
    return (rev <= INT_MAX / 10) && (x == (rev * 10 + org));
}

int main() {

}
