/*
    https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};

// class Solution {
// public:
//     TreeNode* Convert(TreeNode* pRootOfTree)
//     {
//         if(!pRootOfTree || (!pRootOfTree->left && !pRootOfTree->right))
//             return pRootOfTree;

//         vector<TreeNode*> vec;
//         inOrder(pRootOfTree, vec);
//         for(size_t i = 0; i < vec.size(); i++) {
//             if(i == 0) {
//                 vec[i]->left = nullptr;
//                 vec[i]->right = vec[i + 1]; 
//             } else if(i == vec.size() - 1) {
//                 vec[i]->right = nullptr;
//                 vec[i]->left = vec[i - 1];
//             } else {
//                 vec[i]->left = vec[i - 1];
//                 vec[i]->right = vec[i + 1];
//             }
//         }
//         return vec[0];
//     }

//     void inOrder(TreeNode* node, vector<TreeNode*>& vec) {
//         if(!node)
//             return;
//         inOrder(node->left, vec);
//         vec.push_back(node);
//         inOrder(node->right, vec);
//     }
// };

class Solution {
public:
    TreeNode* Convert(TreeNode* root)
    {
        if(!root || (!root->left && !root->right))
            return root;
        TreeNode* node = ConvertCore(root);
        while(node->left)   node = node->left;
        return node;
    }

    TreeNode* ConvertCore(TreeNode* root) {
        if(!root)
            return root;
        if(root->left) {
            TreeNode* left = ConvertCore(root->left);
            while(left->right)
                left = left->right;
            root->left = left;
            left->right = root;
        }
        if(root->right) {
            TreeNode* right = ConvertCore(root->right);
            while(right->left)
                right = right->left;
            root->right = right;
            right->left = root;
        }
        return root;
    }
};