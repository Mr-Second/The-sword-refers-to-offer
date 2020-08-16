/*
    https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int minVal = prices[0];
        int maxDiff = prices[1] - minVal;

        for(int i = 2; i < prices.size(); i++) {
            minVal = min(prices[i - 1], minVal);
            int curDiff = prices[i] - minVal;
            maxDiff = max(curDiff, maxDiff);
        }
        return maxDiff > 0 ? maxDiff: 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices = {7,6,4,3,1};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
