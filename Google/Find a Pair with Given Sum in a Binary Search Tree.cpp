#include <iostream>
#include <stack>

using namespace std;

struct Node {
	Node *left, *right;
	int val;
	Node (int v) : val(v), left(nullptr), right(nullptr) {}
};

void FindPairSum(Node *root, int sum) {
	stack<Node *> smallStack, bigStack;
	smallStack.push(root);
	bigStack.push(root);

	int small = INT_MIN, big = INT_MAX;
	bool nextSmall = true, nextBig = true;
	while (small < big) {
		if (nextSmall) {
			while(!smallStack.empty()) {
				Node *top = smallStack.top();
				if (top != nullptr) {
					smallStack.push(top->left);
				} else {
					smallStack.pop();
					if (!smallStack.empty()) {
						top = smallStack.top();
						small = top->val;
						smallStack.pop();
						smallStack.push(top->right);
						break;
					}
				}
			}
		}

		if (nextBig) {
			while(!bigStack.empty()) {
				Node *top = bigStack.top();
				if (top != nullptr) {
					bigStack.push(top->right);
				} else {
					bigStack.pop();
					if (!bigStack.empty()) {
						top = bigStack.top();
						big = top->val;
						bigStack.pop();
						bigStack.push(top->left);
						break;
					}
				}
			}
		}

		if (small + big == sum) {
			cout << small << " + " << big << " = " << sum << endl;
			return;
		} else if (small + big < sum) {
			nextSmall = true;
			nextBig = false;
		} else {
			nextSmall = false;
			nextBig = true;
		}
	}

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

	FindPairSum(n15, 33);
}