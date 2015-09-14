#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
    unordered_set<string> leftSet, rightSet, tmpSet;
    leftSet.insert(beginWord);
    rightSet.insert(endWord);
    wordDict.erase(beginWord);
    wordDict.erase(endWord);
    int ret = 2, len = beginWord.length();

    while (!leftSet.empty() && !rightSet.empty()) {
        if (leftSet.size() > rightSet.size()) {
            swap(leftSet, rightSet);
        }
        tmpSet.clear();
        for (auto leftItr = leftSet.begin(); leftItr != leftSet.end(); ++leftItr) {
            string word = *leftItr;
            for (int p = 0; p < len; p++) {
                char letter = word[p];
                for (int j = 0; j < 26; j++) {
                    word[p] = 'a' + j;
                    if (rightSet.find(word) != rightSet.end())
                        return ret;
                    if (wordDict.find(word) != wordDict.end()) {
                        tmpSet.insert(word);
                        wordDict.erase(word);
                    }
                }
                word[p] = letter;
            }
        }
        swap(leftSet, tmpSet);
        ret++;
    }
    return 0;
}

int main() {
}
