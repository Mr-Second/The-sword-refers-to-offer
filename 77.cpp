/*
   https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking 
*/


class Solution {
public:
    enum Status{valid = 0, inValid};
    int g_status = valid; 

    int StrToInt(string str) {
        if(str.empty() || (str.size() == 1 && !isdigit(str[0]))) {
            g_status = inValid;
            return 0;
        }

        bool isPositive = true;
        long long res = 0;
        
        for(int i = 0; i < str.length(); i++) {
            if(i == 0 && (str[i] == '-' || str[i] == '+')) {
                isPositive = (str[i] == '+');
            } else if(!isdigit(str[i])) {
                g_status = inValid;
                return 0;
            } else {
                res = res * 10 + (str[i] - '0');
                if(res > INT_MAX || res < INT_MIN) {
                    g_status = inValid;
                    return 0;
                }
            }
        }
        return isPositive ? res: -res;
    }
};
