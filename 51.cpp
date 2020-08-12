/*
    https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
*/
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 2)
            return s.length();
        map<char, int> m;
        int l = 0, r = 0, maxlen = 0;
        while(r < s.length()) {
            char ch = s[r];
            if(m.count(ch)) {
                l = max(l, m[ch] + 1);
            }
            m[ch] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
