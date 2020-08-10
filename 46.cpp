/*
    https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&&tqId=11184&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n < 1)
            return 0;
        int len = getLenOfNum(n);
        if(len == 1)
            return 1;
        int tmp = pow(10, len - 1);
        int high = n / tmp; // 获取n的最高位数
        int hightOneNum = (high == 1) ? n % tmp + 1 : tmp; // 获取n的最高位为1时有多少个数字
        int otherOneNum = high * (len - 1) * (tmp / 10); // 在介于n % tmp到n之间的数字中，除了最高位为1，其余各个数字分别为1 的总数和
        return hightOneNum + otherOneNum + NumberOf1Between1AndN_Solution(n % tmp);
    }

    int getLenOfNum(int num) {
        int len = 0;
        while(num) {
            num /= 10;
            len++;
        }
        return len;
    }
};