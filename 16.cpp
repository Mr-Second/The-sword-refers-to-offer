/*
    https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
     int  NumberOf1(int n) {
         int res = 0;
         while(n) {
             res++;
             n = n & (n - 1);
         }
         return res;
     }
};