#include <iostream>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph (numCourses, vector<int> ());
    vector<int> incoming (numCourses, 0);
    for (auto edge : prerequisites) {
        graph[edge.second].push_back(edge.first);
        incoming[edge.first] += 1;
    }

    vector<int> ret;
    for (int i = 0; i < incoming.size(); i++) {
        if (incoming[i] == 0) {
            incoming[i] = -1;
            ret.push_back(i);
            vector<int> neighbors = graph[i];
            for (int j = 0; j < neighbors.size(); j++) {
                incoming[neighbors[j]] -= 1;
            }
            i = -1;
        }
    }

    for (int i = 0; i < incoming.size(); i++) {
        if (incoming[i] != -1)
            return vector<int> ();
    }

    return ret;
}

int main() {

}
