/*
    https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&&tqId=11183&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int maxSum = INT_MIN;
        int curSum = 0;
        for(int i = 0; i < array.size(); i++) {
           if(curSum <= 0)
				curSum = array[i];
			else
				curSum += array[i];
			maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1,-2,3,10,-4,7,2,-5};
    cout << s.FindGreatestSumOfSubArray(vec) << endl;
    return 0;
}
