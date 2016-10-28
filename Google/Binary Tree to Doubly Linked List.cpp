#include <iostream>
#include <stack>

using namespace std;

struct Node {
	Node *left, *right, *next;
	int val;
	Node (int v) : val(v), left(nullptr), right(nullptr), next(nullptr) {}
};

Node *BinaryTree2SinglyLinkedList(Node *root) {
	Node *ret = new Node (0), *runner = ret;
	stack<Node *> s;
	s.push(root);

	while (!s.empty()) {
		Node *top = s.top();
		if (top != nullptr) {
			s.push(top->left);
		} else {
			s.pop();
			if (!s.empty()) {
				top = s.top();
				runner->next = top;
				runner = top;
				s.pop();
				s.push(top->right);
			}
		}
	}
	return ret->next;
}


Node *BinaryTree2SinglyLinkedList(Node *root) {
	return nullptr;
}

int main() {
    /*
                  15
                /    \
              10     20
             / \    /  \
            8  12  16  25
     */

	Node *n15 = new Node(15);
	Node *n10 = new Node(10);
	Node *n20 = new Node(20);
	Node *n8 = new Node(8);
	Node *n12 = new Node(12);
	Node *n16 = new Node(16);
	Node *n25 = new Node(25);

	n15->left = n10;
	n15->right = n20;
	n10->left = n8;
	n10->right = n12;
	n20->left = n16;
	n20->right = n25;

	// Node *head = BinaryTree2SinglyLinkedList(n15);
	Node *head = BinaryTree2SinglyLinkedListRecur(n15);
	while (head != nullptr) {
		cout << head->val << ", ";
		head = head->next;
	}
}