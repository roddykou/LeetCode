#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* 0->1->2->3  ->  0<-1<-2<-3 */
ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    ListNode *zero = new ListNode(0);
    ListNode *one = new ListNode(1);
    zero->next = one;

    reverseList(zero);

    delete zero;
    delete one;
    zero = NULL;
    one = NULL;
}
