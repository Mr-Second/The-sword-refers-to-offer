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

void prettyPrint(const vector<int>& number) {
    int firstIndex = 0;
    if(number.size() == 1) {
        cout << number[0];
        return; 
    }

    for(int i = 0; i < number.size() - 1; i++) {
        if(number[i] != 0) {
            firstIndex = i;
            break;
        }
        if(number[i] == 0 && number[i + 1] != 0) {
            firstIndex = i + 1;
            break;
        }
    }
    for(int i = firstIndex; i < number.size(); i++) {
        cout << number.at(i);
    }
}

void printNumber(int n) {
    if(n <= 0)
        return;
    vector<int> number(n, 0);
    while(!increment(number)) {
        prettyPrint(number);
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    printNumber(3);
    return 0;
}
