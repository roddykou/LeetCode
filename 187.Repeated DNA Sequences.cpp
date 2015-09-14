#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int char2int(char c) {
	switch(c) {
		case 'A':	return 0;
		case 'C':	return 1;
		case 'G':	return 2;
		case 'T':	return 3;
		default:	return -1;
	}
}

/* don't forget the fist ten-char sequence */
vector<string> findRepeatedDnaSequences(string s) {
	unordered_map<int, int> map;	/* mask to occurance */
	vector<string> ret;
	int mask = 0, i = 0;
	while (i < 9) {
		mask = mask << 2 | char2int(s[i++]);
	}
	while (i < s.length()) {
		mask = (mask << 2 | char2int(s[i])) & 0xFFFFF;
		if (map.find(mask) == map.end()) {
			map[mask] = 1;
		} else if (map[mask]++ == 1) {
			ret.push_back(s.substr(i - 9, 10));
		}
		i++;
	}

	return ret;
}

vector<string> findRepeatedDnaSequences1(string s) {
	int map[0xFFFFF] = {0};
	vector<string> ret;
	int mask = 0, i = 0;
	while (i < 9) {
		mask = mask << 2 | char2int(s[i++]);
	}
	while (i < s.length()) {
		mask = (mask << 2 | char2int(s[i])) & 0xFFFFF;
		if (map[mask]++ == 1) {
			ret.push_back(s.substr(i - 9, 10));
		}
		i++;
	}
	return ret;
}

int main() {
	vector<string> result = findRepeatedDnaSequences1("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ", ";
	}
	cout << endl;
}

