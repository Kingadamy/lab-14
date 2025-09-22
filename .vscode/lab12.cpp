#include <iostream>
#include <array>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

const int DAYS_IN_MONTH = 30;

int main() {
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
    
    // 3. front() and back()
    std::cout << "First day temperature: " << temperatures.front() << "°F\n";
    std::cout << "Last day temperature: " << temperatures.back() << "°F\n\n";
    
    // 4. empty()
    std::cout << "Is array empty? " << (temperatures.empty() ? "Yes" : "No") << "\n\n";
    
    // 5. max_size() 
    std::cout << "Maximum array capacity: " << temperatures.max_size() << "\n\n";
    
    // 6. fill()
    std::array<double, DAYS_IN_MONTH> backup;
    backup.fill(0.0);
    
    // 7. Copy data using iterators
    std::copy(temperatures.begin(), temperatures.end(), backup.begin());
    
    // 8. data() 
    double* ptr = temperatures.data();
    std::cout << "First 5 temperatures using data pointer:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "  Day " << i+1 << ": " << ptr[i] << "°F\n";
    }
    std::cout << "\n";
    
   // min max
    auto minIt = std::min_element(temperatures.begin(), temperatures.end());
    auto maxIt = std::max_element(temperatures.begin(), temperatures.end());
    
    std::cout << "Coldest temperature: " << *minIt << "°F";
    std::cout << " (Day " << std::distance(temperatures.begin(), minIt) + 1 << ")\n";
    
    std::cout << "Hottest temperature: " << *maxIt << "°F";
    std::cout << " (Day " << std::distance(temperatures.begin(), maxIt) + 1 << ")\n\n";
    
    // 10. Calculate average 
    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double average = sum / temperatures.size();
    std::cout << "Average temperature: " << std::fixed << std::setprecision(2) 
              << average << "°F\n\n";
    
    // 11. Count days above average
    int daysAboveAvg = std::count_if(temperatures.begin(), temperatures.end(),
                                      [average](double temp) { return temp > average; });
    std::cout << "Days above average: " << daysAboveAvg << "\n";
    std::cout << "Days below average: " << (DAYS_IN_MONTH - daysAboveAvg) << "\n\n";
    
    // 12. swap() - Swap two arrays
    std::array<double, DAYS_IN_MONTH> forecast;
    forecast.fill(75.0);  // predictred temp
    
    std::cout << "Before swap - First actual temp: " << temperatures.front() << "°F\n";
    std::cout << "Before swap - First forecast temp: " << forecast.front() << "°F\n";
    
    temperatures.swap(forecast);
    
    std::cout << "After swap - First actual temp: " << temperatures.front() << "°F\n";
    std::cout << "After swap - First forecast temp: " << forecast.front() << "°F\n\n";
    
    
    // 13. Reverse iterators 
    std::cout << "Last 5 days (in reverse order):\n";
    auto rit = temperatures.rbegin();
    for (int i = 0; i < 5 && rit != temperatures.rend(); i++, rit++) {
        std::cout << "  " << *rit << "°F\n";
    }
    std::cout << "\n";
    
    // 14. Check for extreme temperatures (using any_of)
    bool hasExtremeCold = std::any_of(temperatures.begin(), temperatures.end(),
                                       [](double temp) { return temp < 32.0; });
    bool hasExtremeHeat = std::any_of(temperatures.begin(), temperatures.end(),
                                       [](double temp) { return temp > 100.0; });
    
    std::cout << "Had freezing days (< 32°F)? " << (hasExtremeCold ? "Yes" : "No") << "\n";
    std::cout << "Had extreme heat (> 100°F)? " << (hasExtremeHeat ? "Yes" : "No") << "\n\n";
    
    // 15. Create sorted copy to find median
    std::array<double, DAYS_IN_MONTH> sorted = temperatures;
    std::sort(sorted.begin(), sorted.end());
    
    double median = sorted.at(DAYS_IN_MONTH / 2);
    std::cout << "Median temperature: " << median << "°F\n\n";
    
    std::cout << "=== End of Weather Report ===\n";
    
    return 0;
}