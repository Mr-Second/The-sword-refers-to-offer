/*
    https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;

        int startRow = 0, startCol = 0, endRow = matrix.size(), endCol = matrix[0].size();

        while(startRow < endRow && startCol < endCol) {
            for(int i = startCol; i < endCol; i++) 
                res.push_back(matrix[startRow][i]);
            startRow++;

            if(startRow >= endRow || startCol >= endCol) break;
            for(int i = startRow; i < endRow; i++) {
                res.push_back(matrix[i][endCol - 1]);
            }
            endCol--;

            if(startRow >= endRow || startCol >= endCol) break;
            for(int i = endCol - 1; i >= startCol; i--)
                res.push_back(matrix[endRow - 1][i]);
            endRow--;
            
            if(startRow >= endRow || startCol >= endCol) break;
            for(int i = endRow - 1; i >= startRow; i--)
                res.push_back(matrix[i][startCol]);
            startCol++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };

    auto res = s.printMatrix(matrix);

    for(auto i: res) {
        cout << i << " ";
    }
    return 0;
}
