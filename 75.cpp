/*
    https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&&tqId=11201&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
        int first = 0, second = 0;
        do
        {
            first = num1 ^ num2;
            second = (num1 & num2) << 1;
            num1 = first;
            num2 = second;
        } while (second != 0);
        return num1;
    }
};