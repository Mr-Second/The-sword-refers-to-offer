/*
    https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&&tqId=11205&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern)    return false;
        return matchCore(str, pattern);
    }

    bool matchCore(char* str, char* pattern) {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        if(*(pattern + 1) == '*') {
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
                return matchCore(str + 1, pattern) || matchCore(str, pattern + 2) || matchCore(str + 1, pattern + 2);
            else
                return matchCore(str, pattern + 2);
        } else {
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
                return matchCore(str + 1, pattern + 1);
            else 
                return false;
        }
    }
};