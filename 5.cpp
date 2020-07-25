/*
    https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int numOfBlank = 0;
        int originalLength = 0;
        for(int i = 0; str[i] != '\0'; i++, originalLength++)
            if(str[i] == ' ')
                numOfBlank++;
        
        int newLength = originalLength + numOfBlank * 2;
        if(newLength > length)
            return;
        //不必减一，因为最后的\0也需要复制
        int p_newArr = newLength;
        int p_originalArr = originalLength;

        while(p_newArr >= 0 && p_originalArr >= 0) {
            if(str[p_originalArr] != ' ') {
                str[p_newArr--] = str[p_originalArr--];
            } else {
                p_newArr -= 3;
                str[p_newArr + 1] = '%';
                str[p_newArr + 2] = '2';
                str[p_newArr + 3] = '0';
                p_originalArr--;
            }
        }
	}
};

int main(int argc, char const *argv[])
{
    Solution s;
    char arr[20] = "hello world";
    s.replaceSpace(arr, 20);
    for(int i = 0; arr[i] != '\0'; i++)
        cout << arr[i] << " ";
    return 0;
}
