// 假设有一个double linked list A<->B<->C<->D<->E。给定 a list of node（unique），
// 返回里面 blocks 的数量比如针对这个list，给定[A,C,B,E] 返回2.  ACB 是一个， E 单独是一个。

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
	char val;
	Node *prev, *next;
	Node(char c) : val (c), prev (nullptr), next (nullptr) {}
};

int numOfBlocks(vector<Node *>& v) {
	int ret = 0;
	unordered_set<Node *> set;
	// for (Node *n : v) {
	// 	ret++;
	// 	if (set.find(n->next) != set.end())	ret--;
	// 	if (set.find(n->prev) != set.end())	ret--;
	// 	set.insert(n);
	// }

	for (Node *n : v) {
		bool nextFound = set.find(n->next) != set.end();
		bool prevFound = set.find(n->prev) != set.end();
		if (!prevFound && !nextFound)
			ret++;
		else if (prevFound && nextFound)
			ret--;
		set.insert(n);
	}

	return ret;
}

int main() {
	Node *A = new Node('A');
	Node *B = new Node('B');
	Node *C = new Node('C');
	Node *D = new Node('D');
	Node *E = new Node('E');

	A->next = B;
	B->prev = A;
	B->next = C;
	C->prev = B;
	C->next = D;
	D->prev = C;
	D->next = E;
	E->prev = D;

	vector<Node *> v = {D, A, C, E, B};
	cout << numOfBlocks(v) << endl;
}