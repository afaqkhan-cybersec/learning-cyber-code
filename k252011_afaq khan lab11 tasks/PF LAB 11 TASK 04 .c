#include <stdio.h>
struct WeatherData {
    char city[100];
    float Temp;
    float coolingFactor;
};
float predictTemperature(struct WeatherData weather, int n, int currentDay, float previousTemp) {
    if (currentDay == n) { 
        return previousTemp;
    } else {
        float currentTemp = previousTemp - weather.coolingFactor;
        return predictTemperature(weather, n, currentDay + 1, currentTemp);
    }
}

int main() {
    struct WeatherData weather;
    int n; 

    printf("Enter City Name: ");
    scanf("%s", weather.city);
    
    printf("Enter Base Temperature: ");
    scanf("%f", &weather.Temp);
    
    printf("Enter Cooling Factor: ");
    scanf("%f", &weather.coolingFactor);
    
    printf("Enter Number of Days: ");
    scanf("%d", &n);

    float temp = predictTemperature(weather, n, 0, weather.Temp);
    printf("\nPredicted temperature for %s after %d days: %.2f\n", weather.city, n, temp);

    return 0;
}

