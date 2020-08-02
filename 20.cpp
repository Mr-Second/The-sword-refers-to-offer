/*
    https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next)
            return pHead;
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = pHead;
        ListNode *cur = dummyNode;

        while(cur->next && cur->next->next) {
            if(cur->next->val == cur->next->next->val) {
                int value = cur->next->val;
                ListNode *differentNode = cur->next->next;
                while(differentNode && differentNode->val == value) {
                    ListNode *node = differentNode;
                    differentNode = differentNode->next;
                    delete node;
                }
                cur->next = differentNode;
            } else
                cur = cur->next;
        }
        ListNode *node = dummyNode;
        pHead = node->next;
        delete node;
        return pHead;
    }
};
//1->2->3->3->4->4->5 
int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next = new ListNode(5);
    root = s.deleteDuplication(root);
    while(root) {
        cout << root->val << "->";
        root = root->next;
    }
    return 0;
}
