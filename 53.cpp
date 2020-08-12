/*
    https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&&tqId=11187&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.size() < 2)
            return -1;
        array<int, 256> hashTable;
        hashTable.fill(0);
        for(char ch: str) {
            hashTable[(int)ch]++;
        }

        for(int i = 0; i < str.length(); i++)
            if(hashTable[(int)str[i]] == 1)
                return i;
        return -1;
    }
};