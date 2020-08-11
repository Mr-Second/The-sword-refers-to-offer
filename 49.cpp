/*
    https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// class Solution {
//     map<int, char> m;
//     vector<string> res;
// public:
//     int translateNum(int num) {
//         string s_num = to_string(num);
//         for(int i = 0; i < 26; i++) 
//             m[i] = 'a' + i;
//         string str = "";
//         translateNum(s_num, 0, str);
//         return res.size();
//     }

//     void translateNum(const string& num, int index, string& str) {
//         if(num.size() == index) {
//             res.push_back(str);
//             return;
//         }
//         string oneBitStr = str;
//         oneBitStr.push_back(m[num[index] - '0']);
//         translateNum(num, index + 1, oneBitStr);

//         if(num[index] != '0' && index < num.size() - 1) {
//             int i = stoi(num.substr(index, 2));
//             if(i < 26) {
//                 string _tmp = str + m[i];
//                 translateNum(num, index + 2, _tmp);
//             }
//         }
//     }

// };

class Solution {
public:
    int translateNum(int num) {
        if(num < 10)
            return 1;
        int rest = num % 100; // 计算十位和个位组成的数
        if(rest < 10 || rest > 25)
            return translateNum(num / 10);
        else
            return translateNum(num / 10) + translateNum(num / 100);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.translateNum(12258) << endl;
    return 0;
}
