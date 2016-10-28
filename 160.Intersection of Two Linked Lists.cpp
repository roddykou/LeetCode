#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *runnerA = headA, *runnerB = headB;
    while (runnerA != NULL && runnerB != NULL) {
        if (runnerA == runnerB)
            return runnerA;
        runnerA = runnerA->next;
        runnerB = runnerB->next;
    }

    ListNode *&shortRunner = runnerA == NULL ? runnerA : runnerB;
    ListNode *&longRunner = runnerA == NULL ? runnerB : runnerA;
    shortRunner = runnerA == NULL ? headB : headA;
    while (longRunner != NULL) {
        shortRunner = shortRunner->next;
        longRunner = longRunner->next;
    }
    longRunner = shortRunner == runnerA ? headA : headB;
    while (shortRunner != NULL && longRunner != NULL) {
        if (shortRunner == longRunner)
            return shortRunner;
        shortRunner = shortRunner->next;
        longRunner = longRunner->next;
    }
    return NULL;
}

int main() {

}
