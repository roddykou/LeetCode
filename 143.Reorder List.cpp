#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) return;
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = slow->next, *curr = prev->next, *next = NULL;
    slow->next = NULL;
    prev->next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    slow = head, fast = prev;
    while (fast != NULL) {
        next = fast->next;
        fast->next = slow->next;
        slow->next = fast;
        slow = fast->next;
        fast = next;
    }
}

int main() {
    
}
