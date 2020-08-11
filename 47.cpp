/*
    https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
*/
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if(n < 0)
            return -1;
        long long level = 1;
        int targetNum = -1;
        while(true) {
            long long bitsOfLevel = getBitsOfLevel(level);
            if(n <= bitsOfLevel) {
                long long base = pow(10, level - 1);
                if(base == 1)
                    base--;
                string number = to_string(n / level + base);
                long long index = n % level;
                targetNum = number[index] - '0';
                break;
            } else {
                n -= bitsOfLevel;
            }
            level++;
        }
        return targetNum;
    }

    long long getBitsOfLevel(long level) {
        if(level == 1)
            return 10L;
        else 
            return static_cast<long long>(9L * pow(10L, level - 1L) * level);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.findNthDigit(1000000000) << endl;
    return 0;
}
