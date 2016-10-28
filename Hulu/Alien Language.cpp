#include <iostream>
#include <vector>

using namespace std;

string printCharacterOrder(vector<string>& dict, int numOfChar) {
	string ret = "";
	vector<int> indegree (numOfChar, 0);
	vector<vector<int> > neighbors (numOfChar, vector<int> ());

	for (int i = 0; i < dict.size() - 1; i++) {
		string word1 = dict[i], word2 = dict[i + 1];
		int j = 0;
		while (j < word1.length() && j < word2.length() && word1[j] == word2[j])
			j++;

		if (j == word1.length() || j == word2.length())
			continue;

		indegree[word2[j] - 'a']++;
		neighbors[word1[j] - 'a'].push_back(word2[j] - 'a');
	}

	// for (int i = 0; i < numOfChar; i++) {
	// 	cout << (char) ('a' + i) << "'s indegree is " << indegree[i] << endl;
	// 	cout << "\t" << "neighbors are: ";
	// 	for (int j = 0; j < neighbors[i].size(); j++) {
	// 		cout << (char) ('a' + neighbors[i][j]) << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < numOfChar; i++) {
		int j = 0;
		while (j < numOfChar && indegree[j] != 0)
			j++;

		indegree[j] = -1;
		ret += (char) ('a' + j);
		for (int k = 0; k < neighbors[j].size(); k++) {
			indegree[neighbors[j][k]]--;
		}
	}

	return ret;
}	

int main() {
	vector<string> words1;
	words1.push_back("baa");
	words1.push_back("abcd");
	words1.push_back("abca");
	words1.push_back("cab");
	words1.push_back("cad");
	cout << printCharacterOrder(words1, 4) << endl;


	vector<string> words2;
	words2.push_back("caa");
	words2.push_back("aaa");
	words2.push_back("aab");
	cout << printCharacterOrder(words2, 3) << endl;
}