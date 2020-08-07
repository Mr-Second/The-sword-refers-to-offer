/*
    https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool isPossible = false;
        stack<int> st;
        int pushIndex = 0, popIndex = 0;
        int pushVSize = pushV.size(), popVSize = popV.size();
        while(pushIndex < pushVSize && popIndex < popVSize) {
            while(pushIndex < pushVSize && (st.empty() || st.top() != popV[popIndex])) {
                st.push(pushV[pushIndex++]);
            }
            if(pushIndex >= pushVSize && st.top() != popV[popIndex])
                break;
            if(st.top() == popV[popIndex]) {
                while(popIndex < popVSize && st.top() == popV[popIndex]) {
                    st.pop();
                    popIndex++;
                }
            }
            if(popIndex == popVSize && pushIndex == pushVSize && st.empty()) {
                isPossible = true;
                break;
            }
        } 
        return isPossible;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,3,5,1,2};

    cout << boolalpha << s.IsPopOrder(pushV, popV);
    return 0;
}
