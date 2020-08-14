/*
    https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int bitNum = 0;
            int shift = 1 << i;
            for(auto num: nums) {
                if((num & shift) != 0)
                    bitNum++;
            }
            if((bitNum % 3) != 0)
                res |= shift;
        }
        return res;
    }
};