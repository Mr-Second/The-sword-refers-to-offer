/*
    https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&&tqId=11194&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;

        int prev = 1, last = 2;
        auto calc = [](int a, int b){return (b + a) *(b - a + 1) / 2;};
        int mid = (sum + 1) / 2;
        int curSum = prev + last;
        while(prev < mid) {
            if(curSum == sum) {
                vector<int> tmp;
                for(int i = prev; i <= last; i++)
                    tmp.push_back(i);
                res.push_back(tmp);
            }
            while(prev < mid && curSum > sum) {
                curSum -= prev;
                prev++;

                if(curSum == sum) {
                     vector<int> tmp;
                    for(int i = prev; i <= last; i++)
                        tmp.push_back(i);
                    res.push_back(tmp);
                }
            }
            last++;
            curSum += last;
        }
        return res;
    }
};