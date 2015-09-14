#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void printRelation(unordered_map<string, vector<string> > &relation) {
    for (auto it = relation.begin(); it != relation.end(); it++) {
        cout << it->first << "->";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << ",";
        }
        cout << endl;
    }
    cout << endl;
}

void buildResult(vector<vector<string> > &ret, unordered_map<string, vector<string> > &relation,
                 string start, string end) {
    ret.push_back(vector<string> (1, start));
    bool finish = false;
    while (!finish) {
        vector<vector<string> > newRet;
        for (int i = 0; i < ret.size(); i++) {
            if (relation.find(ret[i].back()) == relation.end()) continue;
            vector<string> curPath = ret[i], nextWords = relation[curPath.back()];
            for (int j = 0; j < nextWords.size(); j++) {
                curPath.push_back(nextWords[j]);
                newRet.push_back(curPath);
                curPath.pop_back();
                if (nextWords[j] == end)	finish = true;
            }
        }
        ret = newRet;
    }

    auto it = ret.begin();
    while (it != ret.end()) {
        if (it->back() != end)
            it = ret.erase(it);
        else
            it++;
    }
}

bool findRelation(unordered_set<string> &left, unordered_set<string> &right, bool &l2r,
                   unordered_set<string> &dict, unordered_map<string, vector<string> > &relation) {
    if (left.size() > right.size()) {
        swap(left, right);
        l2r = !l2r;
    }
    bool found = false;
    unordered_set<string> newLeft;
    for (auto it = left.begin(); it != left.end(); it++) {
        string word = *it;
        for (int j = 0; j < word.length(); j++) {
            char c = word[j];
            for (char tmp = 'a'; tmp <= 'z'; tmp++) {
                word[j] = tmp;
                if (right.find(word) != right.end()) {
                    found = true;
                    newLeft.insert("dummy");
                    if (l2r)    relation[*it].push_back(word);
                    else        relation[word].push_back(*it);
                } else if (dict.find(word) != dict.end()) {
                    /* we might have path like this from left to right
                     *  "marks","parks"
                     *  "paris","parks" */
                    // dict.erase(word);
                    newLeft.insert(word);
                    if (l2r)    relation[*it].push_back(word);
                    else        relation[word].push_back(*it);
                }
            }
            word[j] = c;
        }
    }
    swap(newLeft, left);
	for(auto itr = left.begin(); itr != left.end(); itr++)
		dict.erase(*itr);
    return found;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    unordered_map<string, vector<string> > relation;
    vector<vector<string> > ret;
    unordered_set<string> left, right;
    left.insert(start);
    right.insert(end);
    dict.erase(start);
    dict.erase(end);
    bool l2r = true;
    while(!findRelation(left, right, l2r, dict, relation) && !left.empty());
    if (!left.empty())  buildResult(ret, relation, start, end);
    return ret;
}

int main () {
    unordered_set<string> dict;
    /* "hot","dot","dog","lot","log" */
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    vector<vector<string> > result = findLadders("hit", "cog", dict);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "->";
        }
        cout << endl;
    }
}
