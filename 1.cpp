/*
 * @Author: MrSecond 
 * @Date: 2020-07-23 15:10:01 
 * @Last Modified by: MrSecond
 * @Last Modified time: 2020-07-23 15:51:12
 */

//数组中任意一个重复的数字
#include <iostream>
#include <vector>
using namespace std;

int findAnyDuplicatedNumber(vector<int>& nums) {
    for(size_t i = 0; i < nums.size(); i++) {
        if(nums[i] != i) {
           while(nums[i] != nums[nums[i]] && nums[i] != i) {
               swap(nums[i], nums[nums[i]]);
           }
            if(nums[i] == i)
                continue;
            if(nums[i] == nums[nums[i]])
                return nums[i];
        }
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    vector<int> nums= {2,3,1,0,2,5,3};
    cout << findFirstNumber(nums) << endl;
    return 0;
}