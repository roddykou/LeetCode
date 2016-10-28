#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPalin(int n) {
	string str = to_string(n);
	int left = 0, right = str.length() - 1;
	while (left < right) {
		if (str[left] != str[right])
			return false;
		left++;
		right--;
	}
	return true;
}

int brutalNearestPalin(int n) {
	int small = n;
	int big = n;
	while (small >= 0) {
		if (isPalin(small))	return small;
		if (isPalin(big))	return big;
		small--;
		big++;
	}
	return -1;
}

int getPalinFromHalf(int highHalf, int totalLength) {
	string strRet;
	string strHighHalf = to_string(highHalf);
	int orignalHalfDigits = (totalLength + 1)/ 2;
	if (strHighHalf.length() == orignalHalfDigits) {
		string strLowerHalf;
		if (totalLength % 2 == 0) {
			strLowerHalf = strHighHalf;
		} else {
			strLowerHalf = strHighHalf.substr(0, orignalHalfDigits - 1);
		}
		reverse(strLowerHalf.begin(), strLowerHalf.end());
		strRet = strHighHalf + strLowerHalf;
	} else if (strHighHalf.length() == orignalHalfDigits + 1) {
		strRet = "1";
		for (int i = 0; i < totalLength - 1; i++)
			strRet += "0";
		strRet += "1";
	} else if (strHighHalf.length() == orignalHalfDigits - 1) {
		for (int i = 0; i < totalLength - 1; i++)
			strRet += "9";
	} else {
		cout << "FUCKING SHIT HERE" << endl;
	}
	return stoi(strRet);
}

int nearestPalin(int n) {
	if (n < 0)	return -1;
	if (n < 10)	return n;
	if (n == 10)	return 9;
	if (n < 17)	return 11;
	if (n < 20)	return 22;

	string str = to_string(n);
	int halfLen = (str.length() + 1 )/ 2;
	string strHalf = str.substr(0, halfLen);

	int originalFlip = getPalinFromHalf(stoi(strHalf), str.length());
	int decrementalFlip = getPalinFromHalf(stoi(strHalf) - 1, str.length());
	int incrementalFlip = getPalinFromHalf(stoi(strHalf) + 1, str.length());

	int originalFlipDiff = abs(originalFlip - n);
	int decrementalFlipDiff = abs(decrementalFlip - n);
	int incrementalFlipDiff = abs(incrementalFlip - n);
	if (originalFlipDiff < min(decrementalFlipDiff, incrementalFlipDiff))
		return originalFlip;
	else if (decrementalFlipDiff < incrementalFlipDiff)
		return decrementalFlip;
	else
		return incrementalFlip;		
}

int main() {
	for (int n = 0; n < 99999; n++)
		if (nearestPalin(n) != brutalNearestPalin(n) && abs(nearestPalin(n) - n) != abs(brutalNearestPalin(n) - n))
			cout << n << " -> " << brutalNearestPalin(n) << " but: " << nearestPalin(n) << endl;
}