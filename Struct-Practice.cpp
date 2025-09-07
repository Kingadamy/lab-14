#include <iostream>
#include <vector>
using namespace std;

struct Part 
{
int quantity;
string partNr;
double density;
int price;
};



int main()
{
    
vector<Part> storeParts;

Part temp;
temp.quantity = 15;
temp.partNr= "IWX";
temp.density = 14.4;
temp.price = 40;

storeParts.push_back(temp);

    return 0;
}