#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>  
using namespace std;

struct Color {
     int red;
     int green;
     int blue;
};

vector<Color> createRandomColors(int count) {
    vector<Color> colors;  
    
    for (int i = 0; i < count; ++i) {
        Color c;  
        
        c.red = rand() % 256;    
        c.green = rand() % 256;  
        c.blue = rand() % 256;   
        
        colors.push_back(c);  
    }
    return colors;
}

int main() {
    srand(time(0));
    
    int n = rand() % 26 + 25;
    
    cout << "Generating " << n << " random colors:" << endl << endl;
    
    vector<Color> colors = createRandomColors(n);
    
    cout << left << setw(8) << "Color#" 
         << right << setw(6) << "Red" 
         << setw(8) << "Green" 
         << setw(6) << "Blue" << endl;
    
    cout << "------" << "------" << "------" << "------" << endl;
    
    for (int i = 0; i < colors.size(); i++) {
        cout << left << setw(8) << (i + 1)
             << right << setw(6) << colors[i].red
             << setw(8) << colors[i].green
             << setw(6) << colors[i].blue << endl;
    }
    
    return 0;
}