/*
    https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&&tqId=11159&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 1)
            return rotateArray[0];
        int MinElement = INT_MAX;
        int left = 0, right = rotateArray.size() - 1;

        while(left <= right) {
            if(right - left == 1) {
                MinElement = rotateArray[right];
                break;
            }
            int mid = ((right - left) >> 1) + left;
            if(rotateArray[left] <= rotateArray[mid]) {
                left = mid;
            } else if(rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }
        return MinElement;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {5,6,7,8,9,10,1,2,3,4};
    cout << s.minNumberInRotateArray(arr) << endl;
    return 0;
}
