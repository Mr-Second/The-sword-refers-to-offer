/*
    https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&&tqId=11203&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length < 1) {
            duplication = nullptr;
            return false;
        }

        vector<int> hashTable(length, 0);
        for(int i = 0; i < length; i++) {
            if(hashTable[numbers[i]] != 0) {
                *duplication = numbers[i];
                return true; 
            } else
                hashTable[numbers[i]]++;
        }
        duplication = nullptr;
        return false;
    }
};