#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* 1->2->3->4  ->  2->1->4->3 */
ListNode* swapPairs(ListNode* head) {
    ListNode dummy (0);
    dummy.next = head;

    ListNode *prev = &dummy, *curr = head, *next = NULL;
    while (prev != NULL && curr != NULL && curr->next != NULL) {
    	next = curr->next;

    	prev->next = next;
    	curr->next = next->next;
    	next->next = curr;

    	prev = curr;
    	curr = prev->next;
    }

    return dummy.next;
}

int main() {

}