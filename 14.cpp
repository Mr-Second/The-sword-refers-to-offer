/*
    https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&&tqId=33257&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int cutRope(int number) {
        if(number < 2)
            return 0;
        if(number <= 3)
            return number - 1;
        int time = number / 3;
        int restNum = number - time * 3;

        if(restNum % 3 == 2) {
            return pow(3, time) * 2;
        } else if(restNum % 3 == 1) {
            return pow(3, time - 1) * 4;
        } else {
            return pow(3, time);
        }
    }
};