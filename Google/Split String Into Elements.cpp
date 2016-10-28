// 12:40

#include <iostream>

using namespace std;

int splitStringHelper(string str, int start, int end) {
	if (start == end)
		return 1;
	else if (start > end)
		return 0;

	string left (1, str[start]);
	string right (1, str[end]);
	while(start < end) {
		if (left == right) {
			return 2 + splitStringHelper(str, start + 1, end - 1);
		} else {
			start++;
			end--;
			left += str[start];
			right = str[end] + right;
			cout << left << " " << right << endl;
		}
	}
	return 1;
}

int splitString(string str) {
	return splitStringHelper(str, 0, str.length() - 1);
}

int main() {
	cout << splitString("teammate") << endl;
	cout << splitString("ab") << endl;
	cout << splitString("aaa") << endl;
	cout << splitString("abeab") << endl;
}
