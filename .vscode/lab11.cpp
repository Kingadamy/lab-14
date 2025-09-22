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
    
    // oorder details
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

int main() {
    
    Restaurant myRestaurant("Adam's Dining Club");
    
    // === Create Order 1: Table 5 ===
    Order& order1 = myRestaurant.createNewOrder(5);
    
    order1.addItem("Caesar Salad", 12.50, 2);
    order1.addItem("Grilled Salmon", 28.00, 1);
    order1.addItem("Pasta Carbonara", 18.50, 1);
    order1.addItem("Red Wine", 8.00, 2);
    order1.display();
    
    // === Create Order 2: Table 2 ===
    Order& order2 = myRestaurant.createNewOrder(2);
    
    order2.addItem("Cappuccino", 4.50, 1);
    order2.addItem("Tiramisu", 8.00, 1);
    order2.markAsPaid();  // This customer already paid
    order2.display();
    
    // === Create Order 3: Table 8 ===
    Order& order3 = myRestaurant.createNewOrder(8);
    
    order3.addItem("Bruschetta", 9.50, 3);
    order3.addItem("Margherita Pizza", 16.00, 2);
    order3.addItem("BBQ Ribs", 32.00, 2);
    order3.addItem("Fish and Chips", 22.00, 1);
    order3.addItem("Chicken Wings", 14.00, 2);
    order3.addItem("icecream sundawe", 6.00, 8);
    order3.addItem("Soft Drinks", 3.50, 4);
    order3.display();
    
    // === Create Order 4: Table 3 ===
    Order& order4 = myRestaurant.createNewOrder(3);
    order4.addItem("Soup of the Day", 7.50, 1);
    order4.addItem("Club Sandwich", 14.00, 1);
    order4.addItem("Iced Tea", 3.00, 1);
    order4.markAsPaid();  
    order4.display();
    
    // === Create Order 5: Table 10 ===
    Order& order5 = myRestaurant.createNewOrder(10);
    order5.addItem("Appetizer Platter", 18.00, 1);
    order5.addItem("Steak Frites", 35.00, 2);
    order5.addItem("Chocolate Mousse", 9.00, 2);
    order5.addItem("Cabernet Sauvignon", 12.00, 1);
    order5.display();
    
    // summary
    myRestaurant.displaySummary();
    
    // table 5 and table 8 are paying
    cout << "\n*** Table 5 is paying their bill ***" << endl;
    order1.markAsPaid();
    order1.display();
    
    cout << "\n*** Table 8 is paying their bill ***" << endl;
    order3.markAsPaid();
    order3.display();
    
    // Final summary
    myRestaurant.displaySummary();
    
    return 0; 
}