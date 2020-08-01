/*
    https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&&tqId=11219&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
#include <utility>
#include <array>
using namespace std;

class Solution {
    vector<vector<bool>> visited;
    int targetNum;
    vector<array<int, 2>> dirs;
    int rowBound;
    int colBound;
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0)
            return 0;
        vector<pair<int, int>> res;
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        targetNum = threshold;
        dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        rowBound = rows;
        colBound = cols;
        int count = moveAndCount(0, 0);
        return count;
    }

    int moveAndCount(int posX, int posY) {
        int res = 0;
        visited[posX][posY] = true;
        if(bitSum(posX) + bitSum(posY) > targetNum)  return res;

        res++;
        for(auto dir: dirs) {
            int x = posX + dir[0];
            int y = posY + dir[1];
            if(checkBounds(x, y)) {
                res += moveAndCount(x, y);
            }
        }
        return res;
    }

    bool checkBounds(int posX, int posY) {
        return posX >= 0 && posX < rowBound && posY >= 0 && posY < colBound && !visited[posX][posY];
    }

    int bitSum(int num) {
        int res = 0;
        while(num != 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.movingCount(10, 1, 100) << endl;
    return 0;
}
