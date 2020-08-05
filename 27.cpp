/*
    https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 && pRoot2) {
            if(pRoot1->val == pRoot2->val)
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }

    bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode *pRoot2) {
        if(!pRoot2)
            return true;
        if(!pRoot1)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return DoesTree1HasTree2(pRoot1->left, pRoot2->left)
        && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(8);
    root->left = new TreeNode(8);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(8);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(2);

    cout << boolalpha << s.HasSubtree(root, root2) << endl;
    return 0;
}
