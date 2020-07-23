#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//如题一但不允许更改数组
int countRange(const vector<int>&nums, int start, int end) {
    int count = 0;
    for_each(nums.begin(), nums.end(), [&](int num){
        if(num <= end && num >= start)
            count++;
    });
    return count;
}

int findAnyDuplicatedNumber(vector<int>& nums) {
    if(nums.size() <= 1)
        return -1;
    int left = 1, right = nums.size() - 1;
    while(right >= left) {
        int mid = ((right - left) >> 1) + left;
        int count = countRange(nums, left, mid); //在数组中找出再left-mid之间数的数量
        if(right == left){
            if(count > 1)
                return left;
            else
                break;
        }
        if(count > (mid - left + 1))
            right = mid;
        else
            left = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,3,5,4,3,2,6,7};
    cout << findAnyDuplicatedNumber(nums) << endl;
    return 0;
}