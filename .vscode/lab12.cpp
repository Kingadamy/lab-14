#include <iostream>
#include <array>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

const int DAYS_IN_MONTH = 30;

int main() {
    // Declare array to store daily temperatures
    std::array<double, DAYS_IN_MONTH> temperatures;
    
    // Read data from file
    std::ifstream inputFile("temperatures.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open temperatures.txt\n";
        std::cerr << "Please ensure the file exists with 30 temperature values.\n";
        return 1;
    }

     // Read temperatures into array
    for (size_t i = 0; i < temperatures.size(); i++) {
        if (!(inputFile >> temperatures[i])) {
            std::cerr << "Error reading temperature at position " << i << "\n";
            return 1;
        }
    }
    inputFile.close();
    
    std::cout << "=== Weather Temperature Monitor ===\n\n";
    
    // 1. size() - Get array size
    std::cout << "Days monitored: " << temperatures.size() << "\n\n";
    
    // 2. at() - Safe access with bounds checking
    std::cout << "Temperature on day 1: " << temperatures.at(0) << "°F\n";
    std::cout << "Temperature on day 15: " << temperatures.at(14) << "°F\n";
    std::cout << "Temperature on day 30: " << temperatures.at(29) << "°F\n\n";
    
    // 3. front() and back() - Access first and last elements
    std::cout << "First day temperature: " << temperatures.front() << "°F\n";
    std::cout << "Last day temperature: " << temperatures.back() << "°F\n\n";
    
    // 4. empty() - Check if array is empty
    std::cout << "Is array empty? " << (temperatures.empty() ? "Yes" : "No") << "\n\n";
    
    // 5. max_size() - Get maximum possible size
    std::cout << "Maximum array capacity: " << temperatures.max_size() << "\n\n";
    
    // 6. fill() - Create a backup array and fill with default value
    std::array<double, DAYS_IN_MONTH> backup;
    backup.fill(0.0);
    
    // 7. Copy data using iterators
    std::copy(temperatures.begin(), temperatures.end(), backup.begin());
    
    // 8. data() - Get pointer to underlying array
    double* ptr = temperatures.data();
    std::cout << "First 5 temperatures using data pointer:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  Day " << i+1 << ": " << ptr[i] << "°F\n";
    }
    std::cout << "\n";