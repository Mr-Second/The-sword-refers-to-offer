/*
    https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&&tqId=11212&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot)
            return res;
        queue<TreeNode*> q;
        q.push(pRoot);
        int subTreeNum = 1;
        int isLeftToRight = true;
        while(!q.empty()) {
            vector<int> oneLevel;
            vector<TreeNode*> oneLevelNodes;

            while(subTreeNum--) {
                oneLevelNodes.push_back(q.front());
                q.pop();
            }
            subTreeNum = 0;
            for(auto& node: oneLevelNodes) {
                oneLevel.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                    subTreeNum++;
                }
                if(node->right) {
                    q.push(node->right);
                    subTreeNum++;
                }
            }

            if(!isLeftToRight)
                reverse(oneLevel.begin(), oneLevel.end());
            res.push_back(oneLevel);
            isLeftToRight = !isLeftToRight;
        }
        return res;
    }
};