// 给一个双链表1<->2<->3<->4<->5, 输入是几个node，比如1，2，5，问有几个connected component
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
	Node *prev, *next;
	int val;
	Node(int v) : val (v), prev (nullptr), next (nullptr) {}
};

int connectedComponents(vector<Node *>& v) {
	int ret = 0;
	unordered_set<Node *> set;

	for (Node *node : v) {
		bool hasPrev = set.find(node->prev) != set.end();
		bool hasNext = set.find(node->next) != set.end();
		if (hasPrev && hasNext)
			ret--;
		else if (!hasPrev && !hasNext)
			ret++;
		set.insert(node);
	}
	return ret;
}

int main() {
	Node *one = new Node(1);
	Node *two = new Node(2);
	Node *three = new Node(3);
	Node *four = new Node(4);
	Node *five = new Node(5);

	one->next = two;
	two->prev = one;
	two->next = three;
	three->prev = two;
	three->next = four;
	four->prev = three;
	four->next = five;
	five->prev = four;

	vector<Node *> v = {one, four, three, two};
	cout << connectedComponents(v) << endl;
}