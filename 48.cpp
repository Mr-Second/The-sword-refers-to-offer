/*
    https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
            return "";
        sort(numbers.begin(), numbers.end(), cmp);
        stringstream ss;
        for(auto& str: numbers)
            ss << to_string(str);
        return ss.str();
    }
    static bool cmp(int s1, int s2) {
        string first = "";
        string second = "";
        first += to_string(s1);
        first += to_string(s2);
        second += to_string(s2);
        second += to_string(s1);

        return first < second; 
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {3,5,1,4,2};
    cout << s.PrintMinNumber(vec) << endl;
    return 0;
}
