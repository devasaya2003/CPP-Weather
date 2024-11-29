#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include "weather.h"
#include "config.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
    userp->append((char *)contents, size * nmemb);
    return size * nmemb;
}

std::string getWeatherDetails(const std::string &city) {
    CURL *curl;
    CURLcode res;
    std::string responseString;

    std::string apiURL = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + API_KEY + "&units=metric";

    // starting a curl session
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, apiURL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            curl_easy_cleanup(curl);
            return "cURL error: " + std::string(curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);

        try {
            auto jsonResponse = nlohmann::json::parse(responseString);
            double temperatue = jsonResponse["main"]["temp"];
            return "Current temperature in " + city + " is " + std::to_string(temperatue) + " degree Celcius.";
        } catch (const std::exception &e) {
            return "Error parsing JSON: " + std::string(e.what());
        }
    }
    return "ERROR INITIALIZING CURL";
}