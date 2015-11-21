#include <iostream>

using namespace std;

/*
	n = 13, return 6: 1, 10, 11, 12, 13
	n = 1401
		1 	-> 1
		00	-> 0
		400	-> 180 = 4 * 20 + 100 = 20 ones per 100 + 100 ones in 1XX;
		1000-> 702 = 1 * 300 + 401 + 1 = 300 ones per 1000 + 401 ones in 1XXX + the one in 1000
*/
int countDigitOne(int n) {
    long long base = 1, last = 0;
    int res = 0;
    while(n >= base){
        int curDigit = (n / base) % 10;
        int lowerDigits = n - (n / base) * base;
        if(curDigit > 1)
            res += curDigit * last + base;
        else if(curDigit == 1)
            res += curDigit * last + lowerDigits + 1;

        /* IMPORTANT: 10->1; 100->20; 1k->300 */
        last = last * 10 + base;
        base = base * 10;
    }
    return res;
}

int main() {

}
