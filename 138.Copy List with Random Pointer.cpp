#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL)   return NULL;

    RandomListNode *curr = head, *next = NULL, *ret = NULL;
    while (curr != NULL) {
        RandomListNode *newNode = new RandomListNode (curr->label);
        next = curr->next;
        newNode->next = next;
        curr->next = newNode;
        curr = next;
    }

    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    curr = head, ret = head->next;
    while (curr->next != NULL) {
        next = curr->next;
        curr->next = next->next;
        curr = next;
    }
    return ret;
}

int main() {

}
