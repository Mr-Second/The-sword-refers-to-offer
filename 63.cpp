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
                if((num & shift) != 0) //判断该位1的个数
                    bitNum++;
            }
            if((bitNum % 3) != 0) //如果该位1的个数不是3的倍数，说明那个数提供了一个1
                res |= shift; //或运算即给该位赋值
        }
        return res;
    }
};