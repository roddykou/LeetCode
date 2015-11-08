#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy (0), *runner = head;

    while (runner != NULL) {
        ListNode *smaller = &dummy, *nextRunner = runner->next;
        while (smaller->next != NULL && smaller->next->val < runner->val)
            smaller = smaller->next;
        runner->next = smaller->next;
        smaller->next = runner;
        runner = nextRunner;
    }

    return dummy.next;
}

int main() {

}
