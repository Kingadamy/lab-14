#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

// create the class here
class color {
private:
    int red;
    int green;
    int blue;

    // now we must call for these using getters and setters
    public:
    int getRed() { return red; }
    void setRed(int r) { red = r; }

    int getGreen() { return green; }
    void setGreen(int g) { green = g; }

    int getBlue() { return blue; }
    void setBlue(int b) { blue = b; }


// this is to print the values

    void print() { 
    cout << setw(15) << "Red: " << red << endl;
    cout << setw(15) << "Green: " << green << endl;
    cout << setw(15) << "Blue: " << blue << endl;
}

};


int main() {
    color c1;
    c1.setRed(365);
    c1.setGreen(56);
    c1.setBlue(7);
    c1.print();


    color c2;
    c2.setRed(123);
    c2.setGreen(454);
    c2.setBlue(29);
    c2.print();

    color c3;
    c3.setRed(456);
    c3.setGreen(234);
    c3.setBlue(234);
    c3.print();

    return 0;


}
    