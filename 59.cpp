/*
    https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&&tqId=11215&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot || k <= 0)
            return nullptr;
        vector<TreeNode*> data;
        inOrder(pRoot, data);
        if(k > data.size())
            return nullptr;
        return data[k - 1];
    }

    void inOrder(TreeNode* node, vector<TreeNode*>& data) {
        if(!node)
            return;
        inOrder(node->left, data);
        data.push_back(node);
        inOrder(node->right, data);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    cout << s.KthNode(root, 3)->val << endl;
    return 0;
}
