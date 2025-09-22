#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    // Declare vector to store daily temperatures
    std::vector<double> temperatures;
    
    // Read data from file
    std::ifstream inputFile("temperatures.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open temperatures.txt\n";
        std::cerr << "Please ensure the file exists with temperature values.\n";
        return 1;
    }
    
    // Read temperatures into vector using push_back
    double temp;
    while (inputFile >> temp) {
        temperatures.push_back(temp);
    }
    inputFile.close();
    
    std::cout << "=== Weather Temperature Monitor (Vector Version) ===\n\n";
    
    // 1. size() - Get vector size
    std::cout << "Days monitored: " << temperatures.size() << "\n\n";
    
    // 2. at() - Safe access with bounds checking
    std::cout << "Temperature on day 1: " << temperatures.at(0) << "°F\n";
    std::cout << "Temperature on day 15: " << temperatures.at(14) << "°F\n";
    std::cout << "Temperature on last day: " << temperatures.at(temperatures.size()-1) << "°F\n\n";
    
    // 3. front() and back()
    std::cout << "First day temperature: " << temperatures.front() << "°F\n";
    std::cout << "Last day temperature: " << temperatures.back() << "°F\n\n";
    
    // 4. empty()
    std::cout << "Is vector empty? " << (temperatures.empty() ? "Yes" : "No") << "\n\n";
    
    // 5. capacity() and max_size() - Vector specific
    std::cout << "Current capacity: " << temperatures.capacity() << "\n";
    std::cout << "Maximum possible size: " << temperatures.max_size() << "\n\n";
    
    // 6. resize() and reserve() - Vector specific
    std::vector<double> backup;
    backup.reserve(temperatures.size());  // Pre-allocate memory
    
    // 7. Copy data using iterators
    std::copy(temperatures.begin(), temperatures.end(), std::back_inserter(backup));
    std::cout << "Backup created with " << backup.size() << " elements\n\n";
    
    // 8. data() 
    double* ptr = temperatures.data();
    std::cout << "First 5 temperatures using data pointer:\n";
    for (int i = 0; i < 5 && i < temperatures.size(); i++) {
        std::cout << "  Day " << i+1 << ": " << ptr[i] << "°F\n";
    }
    std::cout << "\n";
    
    // 9. push_back() and pop_back() - Vector specific
    std::cout << "Adding forecast for next day (predicted: 78.5°F)\n";
    temperatures.push_back(78.5);
    std::cout << "Total days now: " << temperatures.size() << "\n";
    std::cout << "Removing the forecast...\n";
    temperatures.pop_back();
    std::cout << "Back to original size: " << temperatures.size() << "\n\n";
    
    // 10. insert() and erase() - Vector specific
    std::cout << "Inserting a missing temperature (70.0°F) at position 5\n";
    temperatures.insert(temperatures.begin() + 5, 70.0);
    std::cout << "New size after insert: " << temperatures.size() << "\n";
    std::cout << "Removing the inserted value...\n";
    temperatures.erase(temperatures.begin() + 5);
    std::cout << "Size after erase: " << temperatures.size() << "\n\n";
    
    // min max
    auto minIt = std::min_element(temperatures.begin(), temperatures.end());
    auto maxIt = std::max_element(temperatures.begin(), temperatures.end());
    
    std::cout << "Coldest temperature: " << *minIt << "°F";
    std::cout << " (Day " << std::distance(temperatures.begin(), minIt) + 1 << ")\n";
    
    std::cout << "Hottest temperature: " << *maxIt << "°F";
    std::cout << " (Day " << std::distance(temperatures.begin(), maxIt) + 1 << ")\n\n";
    
    // Calculate average 
    double sum = std::accumulate(temperatures.begin(), temperatures.end(), 0.0);
    double average = sum / temperatures.size();
    std::cout << "Average temperature: " << std::fixed << std::setprecision(2) 
              << average << "°F\n\n";
    
    // Count days above average
    int daysAboveAvg = std::count_if(temperatures.begin(), temperatures.end(),
                                      [average](double temp) { return temp > average; });
    std::cout << "Days above average: " << daysAboveAvg << "\n";
    std::cout << "Days below average: " << (temperatures.size() - daysAboveAvg) << "\n\n";
    
    // 11. swap() - Swap two vectors
    std::vector<double> forecast(temperatures.size(), 75.0);  // Vector filled with 75.0
    
    std::cout << "Before swap - First actual temp: " << temperatures.front() << "°F\n";
    std::cout << "Before swap - First forecast temp: " << forecast.front() << "°F\n";
    
    temperatures.swap(forecast);
    
    std::cout << "After swap - First actual temp: " << temperatures.front() << "°F\n";
    std::cout << "After swap - First forecast temp: " << forecast.front() << "°F\n\n";
    
    // Swap back for further operations
    temperatures.swap(forecast);
    
    // 12. Reverse iterators 
    std::cout << "Last 5 days (in reverse order):\n";
    auto rit = temperatures.rbegin();
    for (int i = 0; i < 5 && rit != temperatures.rend(); i++, rit++) {
        std::cout << "  " << *rit << "°F\n";
    }
    std::cout << "\n";
    
    // Check for extreme temperatures (using any_of)
    bool hasExtremeCold = std::any_of(temperatures.begin(), temperatures.end(),
                                       [](double temp) { return temp < 32.0; });
    bool hasExtremeHeat = std::any_of(temperatures.begin(), temperatures.end(),
                                       [](double temp) { return temp > 100.0; });
    
    std::cout << "Had freezing days (< 32°F)? " << (hasExtremeCold ? "Yes" : "No") << "\n";
    std::cout << "Had extreme heat (> 100°F)? " << (hasExtremeHeat ? "Yes" : "No") << "\n\n";
    
    // 13. shrink_to_fit() - Vector specific
    std::cout << "Capacity before shrink: " << temperatures.capacity() << "\n";
    temperatures.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit: " << temperatures.capacity() << "\n\n";
    
    // 14. clear() and reassign - Vector specific
    std::vector<double> weekly_temps;
    weekly_temps.assign(temperatures.begin(), temperatures.begin() + 7);  // First week
    std::cout << "First week extracted: " << weekly_temps.size() << " days\n\n";
    
    // Create sorted copy to find median
    std::vector<double> sorted = temperatures;  // Copy constructor
    std::sort(sorted.begin(), sorted.end());
    
    double median = sorted.at(sorted.size() / 2);
    std::cout << "Median temperature: " << median << "°F\n\n";
    
    // 15. resize() demonstration
    std::cout << "Original size: " << temperatures.size() << "\n";
    temperatures.resize(35, 72.0);  // Extend to 35 days, new days get 72.0°F
    std::cout << "After resize to 35: " << temperatures.size() << "\n";
    std::cout << "New element at position 31: " << temperatures[30] << "°F\n";
    temperatures.resize(30);  // Shrink back to 30
    std::cout << "After resize back to 30: " << temperatures.size() << "\n\n";
    
    std::cout << "=== End of Weather Report ===\n";
    
    return 0;
}