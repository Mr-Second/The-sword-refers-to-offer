/*
    https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&&tqId=11206&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
    int index = 0;
public:
    bool isNumeric(char* str)
    {
        if(!str)
            return false;
        bool numberic = scanInteger(str);
        if(index < strlen(str) && str[index] == '.') {
            ++index;
            numberic = scanUnsignedInteger(str) || numberic;
        }
        if(index < strlen(str) && str[index] == 'e' || str[index] == 'E') {
            ++index;
            numberic = numberic && scanInteger(str);
        }
        return numberic && index == strlen(str);
    }

    bool scanUnsignedInteger(const char* str) 
    {
        int start = index;
        while(index < strlen(str) && str[index] >= '0' && str[index] <= '9') index++;
        return start < index;

    }

    bool scanInteger(const char* str) {
        if(index < strlen(str) && (str[index] == '+' || str[index] == '-')) index++;\
        return scanUnsignedInteger(str);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    char str[] = "12e+4.3";
    cout << boolalpha <<s.isNumeric(str) << endl;
    return 0;
}
