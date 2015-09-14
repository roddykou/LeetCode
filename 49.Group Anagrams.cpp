#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string, set<string> > map;
    for (int i = 0; i < strs.size(); i++) {
        string t = strs[i];
        sort(t.begin(), t.end());
        map[t].insert(strs[i]);
    }
    vector<vector<string> > anagrams;
    for (unordered_map<string, set<string> >::iterator it = map.begin(); it != map.end(); it++) {
        vector<string> anagram(it->second.begin(), it->second.end());
        anagrams.push_back(anagram);
    }
    return anagrams;
}

int main() {
    string a[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> v (a, a + sizeof(a) / sizeof(a[0]));
    vector<vector<string> > result = groupAnagrams(v);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
