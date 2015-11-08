#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* n: number of steps before cycle point.
   c: number of steps inside cycle.
   1. when slow at n, fast is n%c faster than slow.
   2. in other words, fast is (c - n%c) slower than slow.
   3. it takes (c - n%c) steps to make fast meet slow.
   4. they meet at (c - n%c) steps beyond cycle point.
      and it needs n%c or n steps to arrive at cycle point again. */

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }

    if (!fast || !fast->next)
        return NULL;

    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {

}
