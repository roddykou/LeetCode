#include <iostream>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

vector<vector<int> > getGraph(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<vector<int> > ret = vector<vector<int> > (numCourses, vector<int> ());
    for (auto edge : prerequisites) {
        ret[edge.first].push_back(edge.second);
    }
    return ret;
}

vector<int> getIndegree(int numCourses, vector<pair<int, int> >& prerequisites) {
    vector<int> ret = vector<int> (numCourses, 0);
    for (auto edge : prerequisites) {
        ret[edge.second]++;
    }
    return ret;
}


// 每次从第一个节点开始找没有indegree的节点，将其删除。
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int> > graph = getGraph(numCourses, prerequisites);
    vector<int> indegree = getIndegree(numCourses, prerequisites);
    for (int n = 0; n < numCourses; n++) {
        int i = 0;
        while (i < numCourses && indegree[i] != 0)  ++i;
        if (i == numCourses)    return false;
        indegree[i] = -1;
        for (auto neighbor : graph[i]) {
            indegree[neighbor]--;
        }
    }
    return true;
}

int main() {

}
