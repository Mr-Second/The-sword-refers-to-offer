#include <vector>
#include <iostream>
using namespace std;
/*
    执行用时：908 ms, 在所有 C++ 提交中击败了5.01%的用户
    内存消耗：88 MB, 在所有 C++ 提交中击败了7.14%的用户
*/
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.empty() || matrix[0].empty() || target < matrix[0][0] || target > matrix[matrix.size() -1][matrix[0].size() -1])
//             return false;
//         vector<int> rows;
//         int width = matrix[0].size();
//         int height = matrix.size();
//         for(int index = 0; index < height; index++) {
//             if(target <= matrix[index][width - 1] && target >= matrix[index][0]){
//                 rows.push_back(index);
//             }
//         }
//         for(auto rowIndex : rows) {
//             if(binarySearch(matrix[rowIndex], target))
//                 return true;
//         }
//         return false;
//     }

//     bool binarySearch(const vector<int>& nums, int target) {
//         if(nums.empty())
//             return false;
//         size_t left = 0, right = nums.size() - 1;
//         while(left <= right) {
//             size_t mid = ( (right - left) >> 1 ) + left;
//             if(nums[mid] == target)
//                 return true;
//             else if(nums[mid] > target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }
//         return nums[left] == target;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty() || target < matrix[0][0] || target > matrix[matrix.size() -1][matrix[0].size() -1])
            return false;
        int height = matrix.size(), width = matrix[0].size();
        int rowNo = 0, colNo = width - 1;

        while(rowNo < height && rowNo >= 0 && colNo >= 0 && colNo < width) {
            int curVal = matrix[rowNo][colNo];
            if(curVal == target)
                return true;
            else if(curVal > target) {
                colNo--;
            } else {
                rowNo++;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    return 0;
}
