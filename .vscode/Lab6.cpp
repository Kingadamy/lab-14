#include <iostream>
#include <ctime>
using namespace std;

void enterArrayData(double *arr, int size) {
    cout << "Enter " << size << " double values: ";

    for(int i = 0; i < size; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

}


