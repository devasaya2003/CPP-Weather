# **CPP Weather App**

A C++ console-based application that fetches and displays the current temperature of a city using the [OpenWeatherMap](https://openweathermap.org/) API.

---

## **Features**
- Fetches real-time weather data.
- Parses JSON responses using the [nlohmann/json](https://github.com/nlohmann/json) library.
- Displays current temperature in Celsius.
- Allows users to select from a list of cities.

---

## **Prerequisites**
To run this project, ensure you have the following installed:
1. **C++ Compiler**: Supports C++17 or later (e.g., `g++`).
2. **cURL Library**: Required for making HTTP requests.
3. **nlohmann/json** Library:
   - Either install it via your package manager (if available) or download the header file from the [nlohmann/json GitHub repository](https://github.com/nlohmann/json/releases).
4. **OpenWeatherMap API Key**:
   - Sign up at [OpenWeatherMap](https://openweathermap.org/).
   - Generate an API key.

---

## **Setup Instructions**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/<your-username>/CPP-Weather.git
   cd CPP-Weather
   ```

2. **Install Dependencies**:
   - Install the `cURL` library:
     ```bash
     sudo apt install libcurl4-openssl-dev
     ```

   - Install `nlohmann/json`:
     - If your system supports it:
       ```bash
       sudo apt install nlohmann-json3-dev
       ```
     - Alternatively, download the single header file `json.hpp` from the [GitHub releases page](https://github.com/nlohmann/json/releases) and place it in your project directory.

3. **Create `config.h` File**:
   Since `config.h` is ignored in this repository, you need to create it manually:
   - Create a new file named `config.h` in the root directory of the project.
   - Add the following content to the file:
     ```cpp
     #ifndef CONFIG_H
     #define CONFIG_H

     const std::string API_KEY = "your_openweathermap_api_key";

     #endif
     ```
   Replace `"your_openweathermap_api_key"` with your actual API key from OpenWeatherMap.

4. **Compile the Code**:
   Use the following command to compile the project:
   ```bash
   g++ main.cpp weather.cpp -o weather -lcurl -std=c++17
   ```

5. **Run the Program**:
   ```bash
   ./weather
   ```

---

## **How to Use**
1. When prompted, select a city by entering its corresponding number (e.g., `1` for Mumbai, `2` for Delhi).
2. The program will fetch the current temperature for the selected city and display it.

---

## **Available Cities**
The following cities are pre-configured in the program:
1. Mumbai
2. Delhi
3. Bangalore
4. Hyderabad
5. Chennai
6. Kolkata
7. Pune
8. Jaipur
9. Ahmedabad
10. Lucknow

---

## **Contributing**
Feel free to fork the repository and submit pull requests for:
- Adding new features.
- Improving code structure.
- Fixing bugs.

---

## **License**
This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

---

## **Acknowledgments**
- **[OpenWeatherMap](https://openweathermap.org/)** for providing the weather API.
- **cURL** for HTTP requests.
- **[nlohmann/json](https://github.com/nlohmann/json)** for JSON parsing.  
