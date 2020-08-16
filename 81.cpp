/*
    https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int rectCover(int number) {
        if(number <= 0)
            return 0;
        if(number <= 2)
            return number;
        int first = 1;
        int second = 2;
        for(int i = 3; i <= number; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};