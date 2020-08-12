/*
    https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&&tqId=11207&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <array>
#include <iostream>
using namespace std;

class Solution
{
    array<int, 256> timeTable;
    int index;
public:
    Solution(): index(0) {
        timeTable.fill(-1);
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(timeTable[ch] == -1)
            timeTable[ch] = index;
        else if(timeTable[ch] != -2)
            timeTable[ch] = -2;
        index++;
    }
  //return the first appearance once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        int minIndex = INT_MAX;
        for(int i = 0; i < 256; i++) {
            if(timeTable[i] >= 0 && timeTable[i] < minIndex) {
                ch = (char) i;
                minIndex = timeTable[i];
            }
        }
        return ch;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('o');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('l');
    cout << s.FirstAppearingOnce() << endl;
    s.Insert('e');
    cout << s.FirstAppearingOnce() << endl;
    return 0;
}
