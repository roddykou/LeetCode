#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
	int start = 0, ret = 0;
	unordered_map<char, int> map;
	for (int end = 0; end < s.length(); end++) {
		map[s[end]]++;
		while (map.size() > k) {
			map[s[start]]--;
			/* remember to erase the entry */
			if (map[s[start]] == 0)
				map.erase(s[start]);
			start++;
		}
		ret = max(ret, end - start + 1);
	}
	return ret;
}

int lengthOfLongestSubstringKDistinctWithLargeString(string s, int k) {
	int start = 0, ret = 0;

	/* 
     * store the last index we meet the char in the string, later we erase the
     * entry from the map when we meet the last occurance of the character.
     */
	unordered_map<char, int> map;
	for (int end = 0; end < s.length(); end++) {
		map[s[end]] = end;
		while (map.size() > k) {
			if (map[s[start]] == start)
				map.erase(s[start]);
			start++;
		}
		ret = max(ret, end - start + 1);
	}
	return ret;
}

int main() {
	cout << lengthOfLongestSubstringKDistinct("eceba", 2) << endl;
	cout << lengthOfLongestSubstringKDistinctWithLargeString("eceba", 2) << endl;
}