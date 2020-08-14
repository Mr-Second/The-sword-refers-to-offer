/*
    https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&&tqId=11197&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty())
            return str;

        reverse(str, 0, str.length() - 1);

        for(int first = 0, last = 0; last <= str.length(); last++) {
            if(str[last] == ' ' || last == str.length()) {
                reverse(str, first, last - 1);
                first = last + 1;
            }
        }
        return str;
    }

    void reverse(string& str, int begin, int end) {
        while(begin <= end){
            swap(str[begin], str[end]);
            begin++;
            end--;
        }
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "Wonderful";
    cout << s.ReverseSentence(str) << endl;
    return 0;
}
