#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Given 1->1->2->3->3, return 1->2->3. */
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *runner = head, *next;
    while (runner != NULL) {
        next = runner->next;
        while (next != NULL && next->val == runner->val)
            next = next->next;
        runner->next = next;
        runner = next;
    }
    return head;
}

int main() {

}
