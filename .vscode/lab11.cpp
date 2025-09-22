#include <iostream>
#include <vector>

using namespace std;

// struct for menu item
struct MenuItem {
    string name;
    double price;
    int quantity;
};

// need to initialize menu item
   MenuItem(const string& itemName, double itemPrice, int itemQty) 
        : name(itemName), price(itemPrice), quantity(itemQty) {}
};

