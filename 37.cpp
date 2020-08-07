/*
    https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&&tqId=11177&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
    vector<vector<int>> res;
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        if(!root)
            return res;
        vector<int> curPath;
        DFS(curPath, 0, expectNumber, root);
        return res;
    }

    void DFS(vector<int>& curPath, int sum, int target, TreeNode* node) {
        if(!node || sum > target)
            return;
        curPath.push_back(node->val);
        sum += node->val;

        if(sum == target && !node->left && !node->right) {
            res.push_back(curPath);
            curPath.pop_back();
            return;
        }
        DFS(curPath, sum, target, node->left);
        DFS(curPath, sum, target, node->right);
        curPath.pop_back();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    auto res = s.FindPath(root, 22);
    for(auto& vec: res) {
        for(int i: vec) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
