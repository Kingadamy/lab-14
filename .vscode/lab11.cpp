#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// struct for menu item
struct MenuItem {
    string name;
    double price;
    int quantity;

    //initialize menu item
    MenuItem(const string& itemName, double itemPrice, int itemQty) {
        : name(itemName), price(itemPrice), quantity(itemQty) {}
};

// customer order
struct Order {
    int tableNumber;            
    vector<MenuItem> items;     
    double totalPrice;          
    bool isPaid;              // would be cool to track if order is paid or not 
    
    // initialize an order
    Order(int table) : tableNumber(table), totalPrice(0.0), isPaid(false) {}
    
    // need to add item
    void addItem(const string& itemName, double price, int quantity) {
        
        items.push_back(MenuItem(itemName, price, quantity));
        totalPrice += price * quantity;
    }
    
    // display the order details
    void display() const {
        cout << "\n=== Order for Table " << tableNumber << " ===" << endl;
        cout << "Status: " << (isPaid ? "PAID" : "PENDING") << endl;
        cout << "Items ordered:" << endl;
        
        for (const auto& item : items) {
            cout << "  - " << left << setw(20) << item.name 
                 << " (x" << item.quantity << ") @ $" 
                 << fixed << setprecision(2) << item.price 
                 << " each = $" << (item.price * item.quantity) << endl;
        }
        
        cout << "Total: $" << fixed << setprecision(2) << totalPrice << endl;
        cout << "========================" << endl;
    }
    
    // is it paid
    void markAsPaid() {
        isPaid = true;
    }
    
    // how many items
    int getItemCount() const {
        return items.size();
    }
};

