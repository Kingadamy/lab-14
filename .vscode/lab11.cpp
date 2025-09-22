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
    MenuItem(const string& itemName, double itemPrice, int itemQty) 
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

// all restaurant orders
class Restaurant {
private:
    vector<Order> allOrders;    
    string restaurantName;
    
public:
    
    Restaurant(const string& name) : restaurantName(name) {
        cout << "=== " << restaurantName << " Order System ===" << endl;
        cout << "Starting service for the evening...\n" << endl;
    }
    
    // create a new order and return reference to it
    Order& createNewOrder(int tableNumber) {
        cout << "\nNew customers at Table " << tableNumber << "..." << endl;
        
        allOrders.push_back(Order(tableNumber)); 
        return allOrders.back();
    }
    
    // didspslay all orders
    void displayAllOrders() const {
        cout << "\n--- All Current Orders ---" << endl;
        for (const auto& order : allOrders) {
            order.display();
        }
    }
    
    // display the statistics
    void displaySummary() const {
        cout << "\n\n=== RESTAURANT SUMMARY ===" << endl;
        
        double totalRevenue = 0;
        int paidOrders = 0;
        int totalItems = 0;
        
     
        for (const auto& order : allOrders) {
            if (order.isPaid) {
                totalRevenue += order.totalPrice;
                paidOrders++;
            }
            totalItems += order.getItemCount();
        }
        
        cout << "Total orders: " << allOrders.size() << endl;
        cout << "Paid orders: " << paidOrders << endl;
        cout << "Pending orders: " << (allOrders.size() - paidOrders) << endl;
        cout << "Total items ordered: " << totalItems << endl;
        cout << "Revenue from paid orders: $" << fixed << setprecision(2) 
             << totalRevenue << endl;
        cout << "===========================" << endl;
    }
    
};