#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy (0);
    ListNode *runner = &dummy;
    while (l1 != NULL && l2 != NULL) {
        ListNode *&next = l1->val < l2->val ? l1 : l2;
        runner->next = next;
        next = next->next;
        runner = runner->next;
    }

    runner->next = l1 == NULL ? l2 : l1;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;
    return mergeTwoLists(sortList(head), sortList(fast));
}

int main() {
    
}
