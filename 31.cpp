/*
    https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
struct Node {
    int value;
    int curMin;
    Node *next;
    Node(int v): value(v), curMin(v), next(nullptr) {}
};

class Solution {
    Node* head{nullptr};
public:
    void push(int value) {
        if(head == nullptr) {
            head = new Node(value);
        } else {
            Node *newNode = new Node(value);
            newNode->next = head;
            newNode->curMin = std::min(head->value, value);
            head = newNode;
        }
    }
    void pop() {
        Node* delNode = head;
        head = head->next;
        delete delNode;
    }
    int top() {
        return head->value;
    }
    int min() {
        return head->curMin;
    }
};