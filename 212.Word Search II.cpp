#include <vector>
#include <iostream>

using namespace std;

struct TrieNode {
    bool isWordEnd = false;
    TrieNode *children[26] = {0};
    TrieNode () {}
};

TrieNode *root;

void buildTrie(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        TrieNode *runner = root;
        for (int j = 0; j < word.length(); j++) {
            if (runner->children[word[j] - 'a'] == NULL)
                runner->children[word[j] - 'a'] = new TrieNode();
            runner = runner->children[word[j] - 'a'];
        }
        runner->isWordEnd = true;
    }
}

void dfs(vector<vector<char> >& board, vector<string>& ret, int row, int col, TrieNode *parentNode, string str) {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())    return;
    char curChar = board[row][col];
    if (curChar == '0' || parentNode->children[curChar - 'a'] == NULL)  return;
    str += curChar;
    if (parentNode->children[curChar - 'a']->isWordEnd){
        /* IMPORTANT: to avoid dup results */
        parentNode->children[curChar - 'a']->isWordEnd = false;
        ret.push_back(str);
    }
    board[row][col] = '0';
    dfs(board, ret, row + 1, col, parentNode->children[curChar - 'a'], str);
    dfs(board, ret, row - 1, col, parentNode->children[curChar - 'a'], str);
    dfs(board, ret, row, col + 1, parentNode->children[curChar - 'a'], str);
    dfs(board, ret, row, col - 1, parentNode->children[curChar - 'a'], str);
    board[row][col] = curChar;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<string> ret;
    string str = "";
    root = new TrieNode();
    buildTrie(words);
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[0].size(); j++)
            dfs(board, ret, i, j, root, str);
    return ret;
}

int main() {

}
