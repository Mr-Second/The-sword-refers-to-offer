/*
    https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&&tqId=11157&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    vector<int> preOrder;
    vector<int> inOrder;
    int p_root;
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        preOrder = pre;
        InOrder = vin;
        p_root = 0;
        return buildTree(0, pre.size() - 1);
    }

    TreeNode* buildTree(int start, int end) {
        if(start > end)
            return nullptr;
        TreeNode *node = nullptr;

        //在中序序列中找到当前前序遍历序列指针所指元素的位置
        for(int index = start; index <= end; index++) {
            if(inOrder[index] == preOrder[p_root]) {
                node = new TreeNode(preOrder[p_root++]);
                node->left = buildTree(start, index - 1);
                node->right = buildTree(index + 1, end);
                break;
            }
        }
        return node;
    }
};