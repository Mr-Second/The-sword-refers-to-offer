/*
    https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&&tqId=11189&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <stack>
#include <string>
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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2)
            return nullptr;
        
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while(pHead1) {
            st1.push(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2) {
            st2.push(pHead2);
            pHead2 = pHead2->next;
        }
        ListNode* retNode = nullptr;
        while(!st1.empty() && !st2.empty()) {
            if(st1.top() == st2.top()) {
                retNode = st1.top();
            }
            st1.pop();
            st2.pop();
        }
        return retNode;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* head1 = new ListNode(1);
    ListNode* head2 = new ListNode(3);
    ListNode* node = new ListNode(2);
    head1->next = node;
    head2->next = node;
    node->next = new ListNode(4);
    auto res = s.FindFirstCommonNode(head1, head2);
    cout << (res == nullptr ? string("nullptr") : to_string(res->val)) << endl;
    return 0;
}
