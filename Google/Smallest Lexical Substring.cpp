#include <cmath>
#include <iostream>
#include <string>

using namespace std;

string smallestLexicalSubstring(const string& str, const int k) {
	string ret = string (1, str[0]);
	for (int i = 1; i < str.length(); i++) {
		bool inserted = false;
		for (int j = max(0, (int ) (k - (str.length() - i))); j < ret.length(); j++) {
			if (str[i] < ret[j]) {
				ret = ret.substr(0, j) + str[i];
				inserted = true;
				break;
			}
		}
		if (!inserted && ret.length() < k) {
			ret += str[i];
		}
	}
	return ret;
}


int main() {
	cout << smallestLexicalSubstring("pineapple", 3) << endl;
	cout << smallestLexicalSubstring("xyzabc", 3) << endl;
	cout << smallestLexicalSubstring("xyza", 3) << endl;	
}