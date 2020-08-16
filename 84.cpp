/*
    https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&&tqId=11218&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    vector<vector<char>> matrix;
    vector<vector<bool>> visited;
    int height;
    int width;
    string str;
    vector<vector<int>> dirs = {
        {1,0},
        {-1,0},
        {0, 1},
        {0, -1}
    };
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {   
        if(!matrix || !str || rows < 1 || cols < 1)
            return false;
        vector<vector<char>> m(rows, vector<char>(cols));
        for(int i = 0; i < rows * cols; i++) {
            int x = i / cols;
            int y = i % cols;
            m[x][y] = matrix[i];
        }
        this->matrix = m;
        height = rows;
        width = cols;
        this->str = string(str);
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(hasPath(i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool hasPath(int x, int y, int index) {
        if(visited[x][y] || matrix[x][y] != str[index])
            return false;
        if(index == str.length() - 1)
            return true;
        visited[x][y] = true;
        for(auto& dir: dirs) {
            int curX = x + dir[0];
            int curY = y + dir[1];
            if(curX >= 0 && curX < height && curY >= 0 && curY < width && hasPath(curX, curY, index + 1))
                return true;
        }
        visited[x][y] = false;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char str[] = "abcese";
    char matrix[] = "abcesfcsadee";
    cout << boolalpha << s.hasPath(matrix, 3, 4, str) << endl;
    return 0;
}
