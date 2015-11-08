#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy (0), *runner = &dummy;
    dummy.next = head;

    while (runner->next != NULL)
        if (runner->next->val == val)
            runner->next = runner->next->next;
        else
            runner = runner->next;

    return dummy.next;
}

int main() {
    
}
