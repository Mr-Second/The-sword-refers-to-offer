/*
    https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&&tqId=11190&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    int res = 0;
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return res;
        count(data, 0, data.size() - 1, k);
        return res;
    }

    void count(const vector<int>& data, int left, int right, int target) {
        if(left == right) {
            res += (data[left] == target ? 1 : 0);
            return;
        }

        int mid = ((right - left) >> 1) + left;
        if(target > data[mid]) {
            count(data, mid + 1, right, target);
        } else {
            count(data, left, mid, target);
            count(data, mid + 1, right, target);
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1,2,3,3,3,3,4,5};
    cout << s.GetNumberOfK(vec, 3) << endl;
    return 0;
}
