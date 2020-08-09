/*
    https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty())
            return {};
        set<string> st;
        Permutation(str, st, 0);
        vector<string> vec(st.begin(), st.end());
        sort(vec.begin(), vec.end());
        return vec;
    }

    void Permutation(string& str, set<string>&st, int index) {
        if(index == str.length()) {
            st.insert(str);
            return;
        }

        for(int i = index; i < str.length(); i++) {
            swap(str[i], str[index]);
            Permutation(str, st, index + 1);
            swap(str[i], str[index]);
        }
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "aabc";
    auto vec = s.Permutation(str);
    for(auto& s: vec)
        cout << s << " "; 
    return 0;
}
