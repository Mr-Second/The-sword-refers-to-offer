/*
    https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&&tqId=11198&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return  false;
        sort(numbers.begin(), numbers.end());

        int zeroNum = 0;
        int gapNum = 0;
        for(int i = 0; numbers[i] == 0; i++)
            zeroNum++;
        for(int i = zeroNum + 1; i < numbers.size(); i++) {
            if(numbers[i] != numbers[i - 1] + 1) {
                if(numbers[i] == numbers[i - 1])
                    return false;
                gapNum += (numbers[i] - numbers[i - 1] - 1);
            }
        }
        return zeroNum >= gapNum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> num = {0,3,2,6,4};
    cout << boolalpha << s.IsContinuous(num) << endl;
    return 0;
}
