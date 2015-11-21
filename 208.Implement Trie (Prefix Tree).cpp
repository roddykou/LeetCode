#include <string>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd = false;
    TrieNode *children[26] = {0};
    TrieNode() {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *runner = root;
        for (int i = 0; i < word.length(); i++) {
            if (runner->children[word[i]- 'a'] == NULL) {
                runner->children[word[i]- 'a'] = new TrieNode();
            }
            runner = runner->children[word[i]- 'a'];
        }
        runner->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *runner = root;
        for (int i = 0; i < word.length(); i++) {
            if (runner->children[word[i]- 'a'] != NULL) {
                runner = runner->children[word[i]- 'a'];
            } else {
                return false;
            }
        }
        return runner->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *runner = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (runner->children[prefix[i]- 'a'] != NULL) {
                runner = runner->children[prefix[i]- 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("somestring");
    trie.search("key");
}
