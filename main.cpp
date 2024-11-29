#include <iostream>
#include <vector>
#include "weather.h"

int main() {
    std::vector<std::string> cities = {
        "Mumbai", "Delhi", "Bangalore", "Hyderabad", "Chennai",
        "Kolkata", "Pune", "Jaipur", "Ahmedabad", "Lucknow"};

    std::cout << "Available Cities:" << std::endl;
    for (int i = 0; i < cities.size(); i++) {
        std::cout << i + 1 << ". " << cities[i] << std::endl;
    }
    
    int cityIndex;
    std::cout << "Enter a number between 1 and 10 to select a city: ";
    std::cin >> cityIndex;

    if (cityIndex < 1 || cityIndex > 10){
        std::cerr << "Invalid input!\nSelecting default city: " + cities[0] << std::endl;
        cityIndex = 1;
    }

    std::string selectedCity = cities[cityIndex - 1];
    std::cout << "Fetching weather details for " + selectedCity + "..." << std::endl;

    std::string weatherDetails = getWeatherDetails(selectedCity);
    if (!weatherDetails.empty()){
        std::cout << weatherDetails << std::endl;
    }
    else{
        std::cerr << "Failed to fetch weather details!" << std::endl;
    }
}