/*
    https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/comments/
*/

class MaxQueue {
    deque<int> data;
    deque<int> helper;
public:
    MaxQueue() {

    }
    
    int max_value() {
        return helper.empty() ? -1 : helper.front();
    }
    
    void push_back(int value) {
        data.push_back(value);
        while(!helper.empty() && value > helper.back())
            helper.pop_back();
        helper.push_back(value);
    }
    
    int pop_front() {
        if(data.empty())
            return -1;
        int ret = data.front();
        data.pop_front();
        if(ret == helper.front())
            helper.pop_front();
        return ret;
    }
};