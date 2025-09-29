#include <iostream>
#include <iomanip>
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
};

// this is too print the values

void print() {
    cout << setw(W15) << "Red: " << red << endl;
    cout << setw(W15) << "Green: " << green << endl;
    cout << setw(W15) << "Blue: " << blue << endl;
}