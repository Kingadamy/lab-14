#include <iostream>

using namespace std;

class color {
private:
    int red;
    int green;
    int blue;

    public:
    int getRed() { return red; }
    void setRed(int r) { red = r; }

    int getGreen() { return green; }
    void setGreen(int g) { green = g; }

    int getBlue() { return blue; }
    void setBlue(int b) { blue = b; }
};