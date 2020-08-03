/*
    https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&&tqId=11208&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead || !pHead->next)
            return nullptr;
        ListNode *first = pHead->next, *last = first->next;
        while(last && last->next) {
            if(first == last) {
                first = pHead;
                while(first != last) {
                    first = first->next;
                    last = last->next;
                }
                return first;
            } else {
                first = first->next;
                last = last->next->next;
            }
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next;
    cout << s.EntryNodeOfLoop(head)->val << endl;
    return 0;
}
