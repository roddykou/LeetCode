#include <iostream>
#include <queue>          // std::priority_queue
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct mycomparison {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, mycomparison > heap;
    ListNode dummy (0), *runner = &dummy;

    for (int i = 0; i < lists.size(); i++)
        if (lists[i])
            heap.push(lists[i]);

    while (!heap.empty()){
        runner->next = heap.top();
        heap.pop();
        runner = runner->next;
        if (runner->next)
            heap.push(runner->next);
    }

    return dummy.next;
}

int main() {

}
