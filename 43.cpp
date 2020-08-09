/*
    https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&&tqId=11182&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k > input.size() || k <= 0)
            return {};
        if(k == input.size())
            return input;
        int start = 0, end = input.size() - 1;
        int index = Partition(input, start, end);
        while(index != k - 1) {
            if(index > k - 1) {
                end = index - 1;
            } else {
                start = index + 1;
            }
            index = Partition(input, start, end);
        }
        vector<int> res(input.begin(), input.begin() + k);
        return res;
    }

    int Partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        while(start < end) {
            while(start < end && nums[end] >= pivot)
                end--;
            nums[start] = nums[end];
            while(start < end && nums[start] <= pivot)
                start++;
            nums[end] = nums[start];
        }
        nums[start] = pivot;
        return start;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> num = {4,5,1,6,2,7,3,8};
    auto res = s.GetLeastNumbers_Solution(num , 5);
    for(int i: res) 
        cout << i << " ";
    cout << endl;
    return 0;
}
