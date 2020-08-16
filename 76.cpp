/*
    https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&&tqId=11204&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> C(A.size());
        vector<int> D(A.size());
        C[0] = 1;
        D[A.size() - 1] = 1;
        for(int i = 1; i < A.size(); i++)
            C[i] = C[i - 1] * A[i - 1];
        for(int i = A.size() - 2; i >= 0; i--)
            D[i] = D[i + 1] * A[i + 1];
        vector<int> B(A.size());
        for(int i = 0; i < A.size(); i++)
            B[i] = C[i] * D[i];
        return B;
    }
};