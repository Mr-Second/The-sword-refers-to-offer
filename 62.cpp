/*
    https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&&tqId=11193&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) {
            num1 = nullptr;
            num2 = nullptr;
            return;
        }

        int res = data[0];
        for(int i = 1; i < data.size(); i++)
            res ^= data[i];
        int target = 1;
        while((res & 1) == 0) { //找到异或结果中最右边的那个1
            res >>= 1;
            target <<= 1;
        }
        int num_i = 0, num_j = 0; // num_i作为此位为0的那些数的异或结果，num_j表示此位为1的那些数的异或结果
        for(int num: data) {
            if((num & target) == 0) {
                num_i ^= num;
            } else {
                num_j ^= num;
            }
        }
        *num1 = num_i;
        *num2 = num_j;
    }
};