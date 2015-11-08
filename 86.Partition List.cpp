#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode lessHead (0), greaterHead (99);
    lessHead.next = head;
    ListNode *runner = &lessHead, *greaterRunner = &greaterHead;

    while (runner->next != NULL) {
        if (runner->next->val >= x) {
            greaterRunner->next = runner->next;
            runner->next = runner->next->next;
            greaterRunner = greaterRunner->next;
            greaterRunner->next = NULL;
        } else {
            runner = runner->next;
        }
    }

    runner->next = greaterHead.next;
    return lessHead.next;
}

int main() {

}
