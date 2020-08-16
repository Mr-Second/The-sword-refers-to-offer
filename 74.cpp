/*
    https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&&tqId=11200&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        return (int((pow(n, 2) + n))) >> 1;
    }   
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.Sum_Solution(5) << endl;
    return 0;
}
