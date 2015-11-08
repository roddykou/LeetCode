#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *dfs(ListNode *head, ListNode *tail) {
    if (head == tail)
        return NULL;

    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL &&
           fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode *root = new TreeNode (slow->val);
    root->left = dfs(head, slow);
    root->right = dfs(slow->next, tail);

    return root;
}

/* 1->2->3->4->NULL */
TreeNode* sortedListToBST(ListNode* head) {
    return dfs(head, NULL);
}

int main() {
    
}
