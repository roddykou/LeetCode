#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy (INT_MIN), *runner = &dummy;
    dummy.next = head;

    while (runner->next != NULL && runner->next->next != NULL) {
        if (runner->next->val == runner->next->next->val) {
            int dupNumber = runner->next->val;
            ListNode *tmp = runner->next->next->next;
            while (tmp != NULL && tmp->val == dupNumber)
                tmp = tmp->next;
            runner->next = tmp;
        } else {
            runner = runner->next;
        }
    }

    return dummy.next;
}

int main() {
    
}
