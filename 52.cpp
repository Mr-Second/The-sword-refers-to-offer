/*
    https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&&tqId=11186&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)
            return index;
        vector<int> nums{1};
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        while(nums.size() < index) {
            int newNum = min(nums[ptr2] * 2, min(nums[ptr3] * 3, nums[ptr5] * 5));
            nums.push_back(newNum);
            if(newNum == nums[ptr2] * 2) ptr2++;
            if(newNum == nums[ptr3] * 3) ptr3++;
            if(newNum == nums[ptr5] * 5) ptr5++;
        }
        return nums.back();
    }
};