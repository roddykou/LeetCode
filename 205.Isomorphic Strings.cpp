#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;    

    for (int i = 0; i < s.length(); i++) {
    	if (s2t.find(s[i]) == s2t.end()) {
    		if (t2s.find(t[i]) == t2s.end()) {
    			s2t[s[i]] = t[i];
    			t2s[t[i]] = s[i];
    		} else {
    			return false;
    		}
    	} else {
    		if (t2s.find(t[i]) == t2s.end() ||
    			s2t[s[i]] != t[i] ||
    			t2s[t[i]] != s[i]) {
    			return false;
    		}
    	}
    }
    return true;
}

int main() {
	cout << isIsomorphic("paper", "title") << endl;	
	cout << isIsomorphic("ab", "aa") << endl;
}