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
   MenuItem(const string& itemName, double itemPrice, int itemQty) {
        : name(itemName), price(itemPrice), quantity(itemQty) {}
};

// customer order
struct Order {
    int tableNumber;
    vector<MenuItem> items;
    double totalAmount;
    bool isPaid;

    Order(int table) : tableNumber(table), totalAmount(0.0), isPaid(false) {}

    //add item to order
    void addItem(const string& itemName, double price, int quantity) {
         items.push_back(MenuItem(itemName, price, quantity));
        totalPrice += price * quantity;
    }
}
