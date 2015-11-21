#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > q;
    for(int v : nums) {
        if(q.size() < k) {
            q.push(v);
        } else if (v > q.top()) {
            q.pop();
            q.push(v);
        }
    }
    return q.top();
}

int main() {

}
