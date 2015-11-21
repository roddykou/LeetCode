#include <iostream>

using namespace std;

class TrieNode {
public:
    bool isWordEnd = false;
    TrieNode* children[26] = {0};
    TrieNode() {}
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *runner = root;
        for (int i = 0; i < word.length(); i++) {
            if (runner->children[word[i] - 'a'] == NULL)
                runner->children[word[i] - 'a'] = new TrieNode();
            runner = runner->children[word[i] - 'a'];
        }
        runner->isWordEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root, word, 0);
    }
private:
    TrieNode *root = new TrieNode();
    bool searchHelper(TrieNode *root, const string& str, int i) {
        if (i >= str.length())
            return root->isWordEnd;

        TrieNode *runner = root;
        while (i < str.length()) {
            if (str[i] != '.') {
                if (runner->children[str[i] - 'a'] == NULL)
                    return false;
                else
                    runner = runner->children[str[i] - 'a'];
            } else {
                for (int j = 0; j < 26; j++)
                    if (runner->children[j])
                        if (searchHelper(runner->children[j], str, i + 1))
                            return true;
                return false;
            }
            i++;
        }
        return runner->isWordEnd;
    }
};

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    wordDictionary.search("pattern");
}
