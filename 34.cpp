/*
    https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&&tqId=11213&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot)
            return res;
        
        queue<TreeNode*> q;
        q.push(pRoot);
        int subTreeNum = 1;

        while(!q.empty()) {
            vector<TreeNode*>oneLevelNodes;
            vector<int> oneLevel;
            while(subTreeNum--) {
                auto node = q.front();
                q.pop();
                oneLevelNodes.push_back(node);
            }
            subTreeNum = 0;
            for(auto& node: oneLevelNodes) {
                oneLevel.push_back(node->val);
                if(node->left) {
                    subTreeNum++;
                    q.push(node->left);
                }
                if(node->right) {
                    subTreeNum++;
                    q.push(node->right);
                }
            }

            res.push_back(oneLevel);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    auto res = s.Print(root);

    for(auto& vec: res) {
        for(int i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
