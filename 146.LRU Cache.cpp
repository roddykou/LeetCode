#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
struct Node {
    int k, v;
    Node *prev, *next;
    Node () {}
    Node (int key, int value) : k(key), v(value), prev(NULL), next(NULL) {}
};
public:
    LRUCache(int capacity) {
        if (capacity == 0)  cout << "fuck" << endl;
        _capacity = capacity;
        head = NULL;
    }

    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        Node *node = map[key];
        touchNode(node);
        return node->v;
    }

    void set(int key, int value) {
        if (map.find(key) == map.end()) {
            Node *node = new Node (key, value);
            if (map.size() >= _capacity) {
                map.erase(map.find(deleteLRUNode()));
            }
            map[key] = node;
            touchNode(node);
        } else {
            Node *node = map[key];
            touchNode(node);
            node->v = value;
        }
    }

private:
    int _capacity;
    Node *head;         // head is the most recent used node.
    unordered_map<int, Node*> map;

    void touchNode(Node* node) {
        // new node
        if (node->next == NULL && node->prev == NULL) {
            if (head == NULL) {
                head = node;
                head->next = head;
                head->prev = head;
            } else {
                node->next = head;
                node->prev = head->prev;
                head->prev->next = node;
                head->prev = node;
                head = node;
            }
        } else if (node != head) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            node->next = head;
            node->prev = head->prev;
            head->prev->next = node;
            head->prev = node;
            head = node;
        }
    }

    int deleteLRUNode() {
        int deleteKey;
        if (head->next == head && head->prev == head) {
            deleteKey = head->k;
            head = NULL;
        } else {
            Node *del = head->prev;
            del->prev->next = head;
            head->prev = del->prev;
            deleteKey = del->k;
        }
        return deleteKey;
    }
};

int main() {

}
