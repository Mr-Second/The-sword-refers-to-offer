/*
    https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/
*/

class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        if(n < 1)
            return res;
        vector<vector<double>> probabilities(2, vector<double>(6 * n + 1));
        for(auto& arr: probabilities)
            arr.fill(0);
        
        int flag = 0;
        for(int i = 1; i <= 6; i++)
            probabilities[flag][i] = 1;

        for(int level = 2; level <= n; level++) {

            for(int i = 0; i < level; i++)
                probabilities[1 - flag][i] = 0;

            for(int score = level; score <= 6 * level; score++) {
                probabilities[1 - flag][score] = 0;
                for(int curScore = 1; curScore <= score && curScore <= 6; curScore++) 
                    probabilities[1 - flag][score] += probabilities[flag][score - curScore];
            }
        }

        double total = pow(6.0, n);
        for(int i = n; i <= 6 * n + 1; i++)
            res.push_back(static_cast<double>(probabilities[flag][i] / total));
        return res;
    }
};