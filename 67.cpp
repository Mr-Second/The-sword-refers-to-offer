/*
    https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&&tqId=11196&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() < 2)
            return str;
        if(n >= str.length())
            n %= str.length();
        return str.substr(n) + str.substr(0, n);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abcXYZdef";
    cout << s.LeftRotateString(str, 3) << endl;
    return 0;
}

