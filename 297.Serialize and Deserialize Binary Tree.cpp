#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string getString(int& start, const string& data) {
        int end = start;
        while (end < data.length() && data[end] != '|')
            end++;

        string ret = data.substr(start, end - start);
        start = end + 1;
        return ret;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return root == NULL ? "N" : to_string(root->val) + "|" + serialize(root->left) + "|" + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'N') return NULL;

        int index = 0;
        string pre = getString(index, data);
        TreeNode *root = new TreeNode(atoi(pre.c_str()));
        stack<TreeNode *> s;
        TreeNode *curr = root;
        string cur;
        while (index < data.length()) {
            cur = getString(index, data);
            if (pre == "N") {
                if (cur == "N") {
                    curr = s.top();
                    s.pop();
                } else {
                    curr = s.top();
                    s.pop();
                    curr->right = new TreeNode(atoi(cur.c_str()));
                    curr = curr->right;
                }
            } else {
                if (cur == "N") {
                    s.push(curr);
                } else {
                    curr->left = new TreeNode(atoi(cur.c_str()));
                    s.push(curr);
                    curr = curr->left;
                }
            }

            pre = cur;
        }
        return root;
    }
};

int main() {
    // Your Codec object will be instantiated and called as such:
    // Codec codec;
    // codec.deserialize(codec.serialize(root));
}
