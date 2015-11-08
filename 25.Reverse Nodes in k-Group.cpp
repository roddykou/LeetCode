#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1)     return head;

    ListNode dummy (0), *prevEnd = &dummy, *currEnd = head;
    dummy.next = head;
    int i = 1;

    while (currEnd != NULL) {
        if (i == k) {
            ListNode *currStart = prevEnd->next, *nextStart = currEnd->next;
            ListNode *prev = currStart, *runner = currStart->next, *next = NULL;
            while (runner != nextStart) {
                next = runner->next;
                runner->next = prev;
                prev = runner;
                runner = next;
            }
            prevEnd->next = currEnd;
            currStart->next = nextStart;
            prevEnd = currStart;
            currEnd = nextStart;
            i = 1;
        } else {
            currEnd = currEnd->next;
            i++;
        }
    }

    return dummy.next;
}

int main() {
    
}
