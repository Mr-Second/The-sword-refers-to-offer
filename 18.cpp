#include <vector>
#include <iostream>
using namespace std;

bool increment(vector<int>& number) {
    bool isOver = false;
    int flag = 0;
    for(int index = number.size() - 1; index >= 0; index--) {
        if(index == number.size() - 1) {
            number[index]++;
        } else {
            if(!flag)
               break;
            else {
                number[index] += flag;
                flag = 0;
            }
        }

        if(number[index] >= 10) {
            if(index == 0){
                isOver = true;
                break;
            } else {
                number[index] -= 10;
                flag++;
            }
        }
    }
    return isOver;
}

void printNumber(int n) {
    if(n <= 0)
        return;
    vector<int> number(n, 0);
    while(!increment(number)) {
        for(int bit: number) {
            cout << bit;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    printNumber(5);
    return 0;
}
