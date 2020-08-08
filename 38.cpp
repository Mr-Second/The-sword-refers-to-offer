/*
    https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        RandomListNode* curNode = pHead;
        map<RandomListNode*, RandomListNode*> m;
        while(curNode) {
            m[curNode] = new RandomListNode(curNode->label);
            curNode = curNode->next;
        }
        curNode = pHead;
        while(curNode) {
            auto cloneNode = m[curNode];
            cloneNode->next = m[curNode->next];
            cloneNode->random = curNode->random ? m[curNode->random]: nullptr;
            curNode = curNode->next;
        }
        return m[pHead];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    RandomListNode* head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->next->next->next = new RandomListNode(4);
    head->next->next->next->next = new RandomListNode(5);
    
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    RandomListNode* copyHead = s.Clone(head), *curCopyNode = copyHead;

    while(curCopyNode) {
        cout << "Label: " << curCopyNode->label << ", Random Label: " << (curCopyNode->random ? to_string(curCopyNode->random->label) : string("nullptr")) << endl;
        curCopyNode = curCopyNode->next;
    }
    while(copyHead && head) {
        if(head == copyHead || (head->random != nullptr && head->random == copyHead->random))
            cout << "is not deep copy" << endl;
        copyHead = copyHead->next;
        head = head->next;
    }

    return 0;
}
