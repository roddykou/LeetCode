#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<string>& dict, int wordLength, int wordIdx,
		 vector<string>& current, vector<vector<string>>& ret) {
	if (wordIdx == wordLength) {
		ret.push_back(current);
		return;
	}

	for (int i = 0; i < dict.size(); i++) {
		if (dict[i] != "#") {
			int j = 0;
			while (j < current.size() && current[j][wordIdx] == dict[i][j])
				j++;
			if (j == current.size()) {
				string word = dict[i];
				current.push_back(word);
				dict[i] = "#";
				dfs(dict, wordLength, wordIdx + 1, current, ret);
				current.pop_back();
				dict[i] = word;
			}
		}
	}
}

vector<vector<string>> getWordSqure(vector<string> dict) {
	vector<vector<string>> ret;
	vector<string> current;
	dfs(dict, 4, 0, current, ret);
	return ret;
}

int main() {
	vector<string> dict = {"area", "lead", "wall", "lady", "ball"};
	vector<vector<string>> res = getWordSqure(dict);
	for (vector<string> v : res) {
		for (string s : v) {
			cout << s << " ";
		}
		cout << endl;
	}
}