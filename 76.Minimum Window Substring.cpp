#include <vector>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
	int UniqueCharToMatch = 0;  // prevent case we falsely match ABB for T: AAB
	vector<int> table (256, 0);
	for (int i = 0; i < t.length(); i++) {
		 if (table[t[i]] == 0)
			  UniqueCharToMatch++;
		 table[t[i]]++;
	}

	string ret = "";
	int start = 0, end = 0, retLen = INT_MAX;
	while (start < s.length() && end < s.length()) {
		 if (UniqueCharToMatch > 0) {
			  table[s[end]]--;
			  if (table[s[end]] == 0 && s.find(s[end]) != string::npos)
					UniqueCharToMatch--;
			  if (UniqueCharToMatch > 0)
					end++;
		 } else if (UniqueCharToMatch == 0) {
			  if (retLen > end - start + 1) {
					retLen = end - start + 1;
					ret = s.substr(start, retLen);
			  }
			  if (table[s[start]] == 0 && t.find(s[start]) != string::npos) {
					end++;
					UniqueCharToMatch++;
			  }
			  table[s[start]]++;
			  start++;

		 } else {
			  cout << "FUCK!!!" << endl;
		 }
	}
	return ret;	
}

int main() {
	cout << minWindow("aa", "aa") << endl;
	cout << minWindow("ADOBECODEBANC", "ABC") << endl;
	//				   0123456789012
}
