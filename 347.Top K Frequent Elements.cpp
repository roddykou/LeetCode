#include <iostream>
#include <queue>          // std::priority_queue
#include <vector>

using namespace std;

struct Node {
    int num, count;
    Node (int n, int c) : num(n), count(c) {}
};

struct myComparitor {
    bool operator() (const Node *l, const Node *r){
        return l->count < r->count;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int n : nums)
        map[n] += 1;
    
    priority_queue<Node *, vector<Node *>, myComparitor> heap;
    for (auto itr = map.begin(); itr != map.end(); itr++)
        heap.push(new Node(itr->first, itr->second));
    
    vector<int> ret;
    int i = k;
    while (k > 0 && !heap.empty()) {
        ret.push_back(heap.top()->num);
        heap.pop();
        k--;
    }
    
    return ret;
} 

int main() {

}