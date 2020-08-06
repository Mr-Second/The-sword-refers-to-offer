/*
    https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&&tqId=11211&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot || (!pRoot->left && !pRoot->right))
            return true;
      
        return isSymmetrical(pRoot, pRoot);
    }

    bool isSymmetrical(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        if(root1->val != root2->val)
            return false;
        
        return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(5);

    cout << boolalpha << s.isSymmetrical(root) << endl;
    return 0;
}
