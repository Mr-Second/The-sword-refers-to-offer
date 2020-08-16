/*
    https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (!root->left && !root->right) || !p || !q)
            return nullptr;

        if(p == root || q == root || (p->val < root->val && q->val > root->val) || (q->val < root->val && p->val > root->val))
            return root;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);   
    };
}