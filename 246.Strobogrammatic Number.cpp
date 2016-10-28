#include <iostream>

using namespace std;

bool isStrobogrammatic(string num) {
	int left = 0, right = num.length() - 1;
	while (left <= right) {
		if (num[left] == num[right]) {
			if (!(num[left] == '1' || num[left] == '0' || num[left] == '8'))
				return false;
		} else {
			if (!((num[left] == '6' && num[right] == '9') || (num[left] == '9' && num[right] == '6')))
				return false;
		}
		left++;
		right--;
	}
	return true;
}

int main() {
	cout << isStrobogrammatic("69") << endl;
	cout << isStrobogrammatic("88") << endl;
	cout << isStrobogrammatic("818") << endl;
	cout << isStrobogrammatic("898") << endl;
}