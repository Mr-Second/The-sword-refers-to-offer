/*
    https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        next->next = nullptr;
        delete next;
        next = nullptr;
    }
};