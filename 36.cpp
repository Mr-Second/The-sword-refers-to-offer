/*
    https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        int len = sequence.size();
        return VerifySquenceOfBST(sequence, 0, len - 1);
    }

    bool VerifySquenceOfBST(vector<int>& sequence, int left, int right) {
        if(right <= left)
            return true;
        int root = sequence[right];

        int leftBound = left;
        for(; leftBound < right; leftBound++) {
            if(sequence[leftBound] > root)
                break;
        }

        for(int i = leftBound; i < right; i++)
            if(sequence[i] < root)
                return false;
        bool bLeft = VerifySquenceOfBST(sequence, left, leftBound - 1);
        bool bRight = VerifySquenceOfBST(sequence, leftBound, right - 1);

        return (bLeft && bRight);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> sequence = {1,3,2};
    cout << boolalpha << s.VerifySquenceOfBST(sequence) << endl;
    return 0;
}
