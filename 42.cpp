/*
    https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 1)
            return numbers[0];
        int targetNum = numbers[0];
        int time = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(time == 0) {
                targetNum = numbers[i];
                time++;
            } else if(targetNum == numbers[i]) {
                time++;
            } else {
                time--;
            }
        }
        time = 0;
        for(int num: numbers)
            if(num == targetNum)
                time++;
        
        return time > numbers.size() / 2 ? targetNum : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1,2,3,2,2,2,5,4,2};
    cout << s.MoreThanHalfNum_Solution(vec) << endl;
    return 0;
}
