#include <iostream>

using namespace std;

/* 
   题目是给一个positive integer N，求N最少能由几个2^i组成。
   比如N=1的时候，1=2^0，那么N最少能被1个2^0组成。
   再比如N=7的时候，7=4+2+1=2^2+2^1+2^0，这个case中N最少被3个2^i组成。
   然后follow up是，可以同时使用正或负的2^i。同样的例子N=7，在这个情况下，
   7=8-1=2^3-2^0，这样最少只需要2个2^i就能组成N。对大于2个的连续1用减法处理更好
 */
int numOfPowerOfTwo(int n) {
	int ret = 0;
	while (n > 0) {
		ret += (n & 0x1);
		n = n >> 1;
	}
	return ret;
}

int main() {
	cout << numOfPowerOfTwo(1) << endl;
	cout << numOfPowerOfTwo(5) << endl;
	cout << numOfPowerOfTwo(8) << endl;
}