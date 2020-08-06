/*
    https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot || (!pRoot->left && !pRoot->right))
            return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode *left = pRoot->left;
        TreeNode *right = pRoot->right;

        pRoot->left = right;
        pRoot->right = left;
    }
};