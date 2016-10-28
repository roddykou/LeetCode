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
    if (root == nullptr)    return;

    TreeLinkNode *parent = root;
    while (parent != nullptr) {
        TreeLinkNode *childHead = nullptr;
        while(parent != nullptr && childHead == nullptr)
            if (parent->left != nullptr)
                childHead = parent->left;
            else if (parent->right != nullptr)
                childHead = parent->right;
            else
                parent = parent->next;

        TreeLinkNode *childRunner = childHead, *childNext = nullptr;
        while (childRunner != nullptr) {
            while (parent != nullptr && childNext == nullptr) {
                if (childRunner == parent->left && parent->right != nullptr) {
                    childNext = parent->right;
                } else if (childRunner != parent->left && parent->left != nullptr) {
                    childNext = parent->left;
                    break;
                } else if (parent->right != nullptr) {
                    childNext = parent->right;
                }
                parent = parent->next;
            }
            childRunner->next = childNext;
            childRunner = childNext;
            childNext = nullptr;
        }
        parent = childHead;
    }
}

int main() {

}
