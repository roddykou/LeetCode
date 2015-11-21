#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == NULL)   return NULL;

    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);

    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    map[node] = newNode;

    stack<UndirectedGraphNode *> s;
    s.push(node);

    while (!s.empty()) {
        UndirectedGraphNode *oldNode = s.top();
        s.pop();
        for (UndirectedGraphNode *neighbor : oldNode->neighbors) {
            if (map.find(neighbor) == map.end()) {
                UndirectedGraphNode *tmp = new UndirectedGraphNode(neighbor->label);
                map[oldNode]->neighbors.push_back(tmp);
                map[neighbor] = tmp;
                s.push(neighbor);
            } else {
                map[oldNode]->neighbors.push_back(map[neighbor]);
            }
        }
    }
    return map[node];
}

int main() {

}
