/*
    https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       if(nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == mid) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return left;
    }
};