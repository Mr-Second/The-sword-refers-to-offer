/*
    https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&&tqId=11199&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        int last = 0;
        for(int i = 2; i <= n; i++) 
            last = (last + m) % i;
            return last;
    }

    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        if(n == 1)
            return 0;
        Node *head = new Node(0);
        Node *cur = head;
        for(int i = 1; i < n; i++) {
            cur->next = new Node(i);
            cur->next->prev = cur;
            cur = cur->next;
        }
        cur->next = head;
        head->prev = cur;
        Node *start = head;
        int len = n;
        int step = m;
        while(len > 1) {
            cur = start;
            step = m;
            while(--step) 
                cur = cur->next;

            start = cur->next;
            Node* prev = cur->prev;

            cur->next = nullptr;
            cur->prev = nullptr;
            prev->next = start;
            start->prev = prev;
            delete cur;
            len--;
        }
        return start->val;
    }

    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v): val(v), next(nullptr), prev(nullptr) {}
    };
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.LastRemaining_Solution(5, 3) << endl;
    return 0;
}
