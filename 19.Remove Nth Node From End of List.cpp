#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *tail = head, *runner = head;
    for (int i = 0; i < n; i++)
        tail = tail->next;

    if (tail == NULL)
        return head->next;

    while (tail->next != NULL) {
        runner = runner->next;
        tail = tail->next;
    }

    runner->next = runner->next->next;
    return head;
}

int main() {

}
