/*
    https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&&tqId=11188&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    long long inversePairsNum = 0;
public:
    int InversePairs(vector<int> data) {
        if(data.size() < 2)
            return data.size();
        count(data, 0, data.size() - 1);
        return inversePairsNum % 1000000007;
    }

    void count(vector<int>& data, int start, int end) {
        if(start >= end)
            return;
        int mid = ((end - start) >> 1) + start;
        count(data, start, mid);
        count(data, mid + 1, end);

        vector<int> left(data.begin() + start, data.begin() + mid + 1);
        vector<int> right(data.begin() + mid + 1, data.begin() + end + 1);

        int dataIndex = end, leftIndex = left.size() - 1, rightIndex = right.size() - 1;

        while(leftIndex >= 0 && rightIndex >= 0) {
            if(left[leftIndex] > right[rightIndex]) {
                inversePairsNum += (rightIndex + 1);
                data[end] = left[leftIndex];
                leftIndex--;
            } else {
                data[end] = right[rightIndex];
                rightIndex--;
            }
            end--;
        }
        while(leftIndex >= 0)
            data[end--] = left[leftIndex--];
        while(rightIndex >= 0)
            data[end--] = right[rightIndex--];
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {1,2,3,4,5,6,7,0};
    cout << s.InversePairs(data) << endl;
    return 0;
}
