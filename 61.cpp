/*
    https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&&tqId=11192&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot || (!pRoot->left && !pRoot->right))
            return true;
        int depth;
        return isBalanced(pRoot, &depth);
    }
    bool isBalanced(TreeNode* root, int* depth) {
        if(!root) {
            *depth = 0;
            return true;
        }
        int left, right;
        if(isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
            if(abs(left - right) <= 1) {
                *depth = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << boolalpha << s.IsBalanced_Solution(root) << endl;
    return 0;
}
