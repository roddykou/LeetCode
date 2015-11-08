#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy (0), *runner = &dummy;
    int carry = 0, sum = 0;
    while (l1 != NULL && l2 != NULL) {
        sum = carry + l1->val + l2->val;
        ListNode *newNode = new ListNode (sum % 10);
        runner->next = newNode;
        runner = newNode;
        l1 = l1->next;
        l2 = l2->next;
        carry = sum / 10;
    }

    ListNode *remain = l1 == NULL ? l2 : l1;
    while (remain != NULL) {
        sum = carry + remain->val;
        ListNode *newNode = new ListNode (sum % 10);
        runner->next = newNode;
        runner = newNode;
        remain = remain->next;
        carry = sum / 10;
    }

    if (carry > 0) {
        ListNode *newNode = new ListNode (carry);
        runner->next = newNode;
    }

    return dummy.next;
}

int main() {
    
}
