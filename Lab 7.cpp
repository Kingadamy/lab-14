#include <iostream>
using namespace std;

string *reverseArray(string *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        string temp = arr[i];                    
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    return arr;                                 

}