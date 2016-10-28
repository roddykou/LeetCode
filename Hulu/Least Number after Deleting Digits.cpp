#include <iostream>
#include <string>

using namespace std;

string trimNumber(string number, int digit) {
	cout << "trimming number " << number << " with " << digit << " digits \t";
	string ret = number;
	int start = 0;
	while (digit > 0 && ret.length() > 0) {
		int i = start;
		while (i < ret.length() - 1 && ret[i] <= ret[i + 1])
			i++;

		if (i == ret.length() - 1 || i == 0)
			start = 0;
		else
			start = i - 1;

		ret.erase(ret.begin() + i);
		digit--;
	}

	return ret;
}

int main() {
	cout << "got " << trimNumber("13243221", 5) << " expected 121" << endl;
	cout << "got " << trimNumber("1234567", 3) << " expected 1234" << endl;
	cout << "got " << trimNumber("7654321", 3) << " expected 4321" << endl;
	cout << "got " << trimNumber("66666666", 3) << " expected 66666" << endl;
	cout << "got " << trimNumber("12345", 5) << " expected " << endl;
	cout << "got " << trimNumber("12345", 6) << " expected " << endl;
	cout << "got " << trimNumber("12345", 0) << " expected 12345" << endl;
	cout << "got " << trimNumber("24635", 3) << " expected 23" << endl;
}