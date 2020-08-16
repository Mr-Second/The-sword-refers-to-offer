/*
    https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&&tqId=11154&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int height = array.size();
        if(height < 1)
            return false;
        int width = array[0].size();
        if(width < 1)
            return false;

        int x = 0, y = width - 1;
        while(x >= 0 && x < height && y >= 0 && y < width) {
            int curVal = array[x][y];
            if(curVal == target)
                return true;
            else if(curVal < target) x++;
            else y--;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix = {
        {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15}
    };
    cout << boolalpha << s.Find(7, matrix) << endl;
    return 0;
}
