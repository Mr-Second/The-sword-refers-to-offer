/*
    https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&&tqId=11216&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <functional>
using namespace std;

class Solution {
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    void Insert(int num)
    {
        if(left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        //左右两部分数量相差不能超过1
        if(left.size() == right.size() + 2) right.push(left.top()), left.pop();
        //始终保持，左半部分.size() - 右半部分.size() <= 1, 因为这样，中位数就只可能是两者之和除以2.0或者左半部分堆顶
        if(left.size() + 1 == right.size()) left.push(right.top()), right.pop();
    }

    double GetMedian()
    { 
        return left.size() == right.size() ? ((left.top() + right.top()) / 2.0): left.top();;
    }
};