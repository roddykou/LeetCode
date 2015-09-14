#include <vector>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
	int distinctCharsToMatch = 0;
	vector<int> charsToMatch (256, 0);
	for (int i = 0; i < t.length(); i++) {
		if (charsToMatch[t[i]] == 0)
			distinctCharsToMatch++;
		charsToMatch[t[i]]++;
	}

	string ret = "";
	int start = 0, end = 0, retLen = INT_MAX;
	while (start < s.length() && end < s.length()) {
		cout << "distinctCharsToMatch: " << distinctCharsToMatch << " start: " << start << " end: " << end << endl;
		if (distinctCharsToMatch > 0) {
			charsToMatch[s[end]]--;
			if (charsToMatch[s[end]] == 0 && t.find(s[end]) != string::npos) {
				distinctCharsToMatch--;
			}
			if (distinctCharsToMatch > 0) {
				end++;
			}
		} else if (distinctCharsToMatch == 0) {
			if (charsToMatch[s[start]] == 0 && t.find(s[start]) != string::npos) {
				if (retLen > end - start + 1) {
					retLen = end - start + 1;
					ret = s.substr(start, retLen);
					cout << "ret: " << ret << endl;
				}
				/* Don't forget this one */
				end++;
				distinctCharsToMatch++;
			}
			charsToMatch[s[start]]++;
			start++;
		} else {
			cout << "FUCK" << endl;
		}
	}
	return ret;
}

int main() {
	cout << minWindow("aa", "aa") << endl;
	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
	//				   0123456789012
}