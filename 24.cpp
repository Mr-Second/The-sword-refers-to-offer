/*
    https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* first = pListHead, *last = pListHead;
        while(last && --k) {
            last = last->next;
        }
        if(k != 0 && last == nullptr) {
            return nullptr;
        }

        while(last->next) {
            last = last->next;
            first = first->next;
        }
        return first;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    cout << s.FindKthToTail(head, 1)->val << endl;

    return 0;
}
