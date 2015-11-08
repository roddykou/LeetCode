#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummy (0);
    dummy.next = head;

    ListNode *reverseHeadPrev = &dummy;
    for (int i = 1; i < m; i++)
        reverseHeadPrev = reverseHeadPrev->next;

    ListNode *prev = reverseHeadPrev, *curr = prev->next, *next = NULL;
    for (int i = m; i <= n; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    reverseHeadPrev->next->next = curr;
    reverseHeadPrev->next = prev;

    return dummy.next;
}

int main() {
    
}
