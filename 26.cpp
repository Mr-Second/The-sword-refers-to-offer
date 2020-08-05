/*
    https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        
        ListNode *dummyHead = new ListNode(0), *curNode = dummyHead;
        while(pHead1 && pHead2) {
            if(pHead1->val < pHead2->val) {
                curNode->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curNode->next = pHead2;
                pHead2 = pHead2->next;
            }
            curNode = curNode->next;
        }

        while(pHead1) {
            curNode->next = pHead1;
            pHead1 = pHead1->next;
            curNode = curNode->next;
        }

        while(pHead2) {
            curNode->next = pHead2;
            pHead2 = pHead2->next;
            curNode = curNode->next;
        }
        curNode = dummyHead->next;
        delete dummyHead;
        return curNode;
    }
};