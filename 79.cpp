/*
    https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
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

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (!root->left && !root->right) || !p || !q)
            return nullptr;
        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;
        pPath.push_back(root);
        qPath.push_back(root);
        bool pRes = getPath(root, p, pPath);
        bool qRes = getPath(root, q, qPath);
        
        if(!pRes || !qRes)
            return nullptr;
        
        TreeNode* lowestCommonAncestor = nullptr;
        int shorterLen = min(pPath.size(), qPath.size()); 

        for(int i = 0; i < shorterLen; i++) 
            if(pPath[i] == qPath[i])
                lowestCommonAncestor = pPath[i];
        
        return lowestCommonAncestor;
    }

    bool getPath(TreeNode * root, TreeNode * targetNode, vector<TreeNode*>& path) {
        if(root == targetNode) {
            return true;
        }
        bool res = false;
        if(root->left) {
            path.push_back(root->left);
            res = getPath(root->left, targetNode, path);
            if(!res)
                path.pop_back();
        }
        if(!res && root->right) {
            path.push_back(root->right);
            res = getPath(root->right, targetNode, path);
            if(!res)
                path.pop_back();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    cout << s.lowestCommonAncestor(root, root->left, root->left->right)->val << endl;

    return 0;
}
