#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int res = 0, left = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
        ++m[s[i]];
        while (m.size() > k) {
            if (--m[s[left]] == 0) m.erase(s[left]);
            ++left;
        }
        res = max(res, i - left + 1);
    }
    return res;
}

int main() {
	
}