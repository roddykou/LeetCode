#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)   return true;

    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = slow, *curr = slow->next, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode *left = head, *right = prev;
    slow->next = NULL;
    while (left != slow) {
        cout << left << " " << slow << endl;
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}

int main() {
    ListNode one (1);
    ListNode two (0);
    ListNode three (1);
    one.next = &two;
    two.next = &three;
    cout << isPalindrome(&one) << endl;
}
