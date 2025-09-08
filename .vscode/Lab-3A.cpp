#include <iostream>
#include <string>
using namespace std;

struct Restaurant {
    string name;          
    string address;        
    string cuisine;        
    double rating;       
    int capacity;
};

Restaurant createRestaurant() {
    Restaurant temp;
   
    cout << "Enter restaurant info: ";
      
    cout << "Restaurant Name: ";
    getline(cin, temp.name);
    
    cout << "Address: ";
    getline(cin, temp.address);
    
    cout << "Cuisine Type: ";
    getline(cin, temp.cuisine);
    
   cout << "Rating: ";
    cin >> temp.rating;

    cout << "Capacity: ";
    cin >> temp.capacity;    

    cin.ignore();

    return temp;
}

void displayRestaurant(const Restaurant& r) {
    cout << "Restaurant Details:\n";
    cout << "Name: " << r.name << endl;
    cout << "Address: " << r.address << endl;
    cout << "Cuisine: " << r.cuisine << endl;
    cout << "Rating: " << r.rating << endl;
    cout << "Capacity: " << r.capacity << endl;
}


int main() {
    Restaurant r1 = createRestaurant();
    Restaurant r2 = createRestaurant();
    Restaurant r3 = createRestaurant();
    Restaurant r4 = createRestaurant();

    displayRestaurant(r1);
    displayRestaurant(r2);
    displayRestaurant(r3);
    displayRestaurant(r4);

    return 0;
}

