/*
    https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&&tqId=11195&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.size() < 2)
            return res;
        int left = 0, right = array.size() - 1;
        while(left < right) {
            int curSum = array[left] + array[right];
            if(curSum == sum) {
                res.push_back(array[left]);
                res.push_back(array[right]);
                break;
            } else if(curSum < sum) left++;
            else right--;
        }
        return res;
    }
};