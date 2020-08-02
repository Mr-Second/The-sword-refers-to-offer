/*
    https://leetcode-cn.com/problems/excel-sheet-column-title/
*/
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0)
            return "";
        string res;
        while(n > 0) {
            n--;
            res += ('A' + n % 26);
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.convertToTitle(28) << endl;
    return 0;
}
