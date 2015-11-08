#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
        1
       / \
      2  3
     /   /
    4   5
   /   / \
  6   7   8
*/
void connect(TreeLinkNode *root) {
    TreeLinkNode *parent = root, *head = NULL;
    while (parent) {
        TreeLinkNode *cur, *next;
        while (parent) {
            if (parent->left) {
                cur = parent->left;
                break;
            } else if (parent->right) {
                cur = parent->right;
                break;
            } else {
                parent = parent->next;
            }
        }

        head = cur, next = cur;

        while (parent) {
            if (parent->left == NULL && parent->right == NULL) {
                parent = parent->next;
            } else if (parent->left && parent->right == NULL) {
                if (next == parent->left) {
                    parent = parent->next;
                } else {
                    next = parent->left;
                    cur->next = next;
                    cur = next;
                    parent = parent->next;
                }
            } else if (parent->left == NULL && parent->right) {
                if (next == parent->right) {
                    parent = parent->next;
                } else {
                    next = parent->right;
                    cur->next = next;
                    cur = next;
                    parent = parent->next;
                }
            } else {
                if (next == parent->left) {
                    next = parent->right;
                    cur->next = next;
                    cur = next;
                } else if (next == parent->right) {
                    parent = parent->next;
                } else {
                    next = parent->left;
                    cur->next = next;
                    cur = next;
                }
            }
        }
        parent = head;
    }
}

int main() {

}
