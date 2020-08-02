/*
    https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&&tqId=11165&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(abs(base) < 1e-8 && exponent <= 0)
            throw domain_error("base can't be zero when exponent <= 0");
        if(abs(base - 1) < 1e-8 || exponent == 0)
            return 1.0;
        else if(exponent < 0) {
            return _pow(1 / base, -exponent);
        } else{
            return _pow(base, exponent);
        }    
    }

    double _pow(double base, int exponent) {
        if(exponent == 1)
            return base;
        double res = _pow(base, exponent / 2);
        if(exponent & 1) {
            res *= (res * base);
        } else {
            res *= res;
        }
        return res;
    }
};