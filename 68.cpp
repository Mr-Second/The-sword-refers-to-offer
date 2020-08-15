/*
    https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&&tqId=11217&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if(num.empty() || size > num.size() || size < 1)
            return {};

        vector<int> res;
        deque<int> index;
        for(int i = 0; i < size; i++) {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }

        for(int i = size; i < num.size(); i++) {
            res.push_back(num[index.front()]);

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();

            while(!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();

            index.push_back(i);
        }
        res.push_back(num[index.front()]);
        return res;
    }
};