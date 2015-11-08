#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL)   return NULL;

    ListNode dummy (0), *slow = &dummy, *fast = head;
    dummy.next = head;

    int n = 0;
    while (fast != NULL) {
        fast = fast->next;
        n++;
    }

    k = k % n;
    if (k == 0)
        return head;

    fast = &dummy;
    for (int i = 0; i < k; i++)
        fast = fast->next;

    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    dummy.next = slow->next;
    slow->next = NULL;
    fast->next = head;
    return dummy.next;
}

int main() {

}
