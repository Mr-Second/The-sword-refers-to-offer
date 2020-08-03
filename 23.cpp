/*
    https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size() < 2)
            return;
        vector<int> oddArr;
        vector<int> evenArr;
        for(auto num: array) {
            if(num & 1)
                oddArr.push_back(num); 
            else
                evenArr.push_back(num);
        }
        array.clear();
        vector<int>(array).swap(array);
        array.insert(array.end(), oddArr.begin(), oddArr.end());
        array.insert(array.end(), evenArr.begin(), evenArr.end());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7};
    s.reOrderArray(arr);
    for(auto num: arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
