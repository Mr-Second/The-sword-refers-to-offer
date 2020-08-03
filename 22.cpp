/*
    https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&&tqId=11206&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <regex>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumeric(char* str)
    {
        regex pattern("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
        return regex_match(str, pattern);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    char str[] = "12e+4.3";
    cout << boolalpha <<s.isNumeric(str) << endl;
    return 0;
}
