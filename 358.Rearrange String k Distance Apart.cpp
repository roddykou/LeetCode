#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

/* 
 * Keep a max heap from charaters that needs to be append to (string) ret.
 * Take k chars each time, append to the ret and put them back after decrementing
 * their occurrace. If there is not enough chars to be appended, which means we
 * need to append one char more than once, and there won't be a valid answer.
 */
string rearrangeString(string str, int k) {
    string ret;
    unordered_map<char, int> map;
    priority_queue<pair<int, char>> q;

    for (char a : str) ++map[a];
    for (auto it = map.begin(); it != map.end(); ++it)
        q.push({it->second, it->first});

    while (ret.length() < str.length()) {
    	string tmp;
    	int tmpLength = min(k, (int) (str.length() - ret.length()));
    	vector<pair<int, char>> v;
    	for (int i = 0; i < tmpLength; i++) {
    		if (q.empty())	return "NO ANSWER";
    		pair<int, char> p = q.top();
    		q.pop();
    		ret += p.second;
    		if (--p.first > 0)	v.push_back(p);
    	}

    	for (pair<int, char> p : v)	q.push(p);
    }

    return ret;
}

int main () {
	cout << rearrangeString("aabbcc", 3) << endl;
	cout << rearrangeString("aaabc", 3) << endl;
	cout << rearrangeString("aaadbbcc", 2) << endl;
}