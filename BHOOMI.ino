#include <Arduino.h>

const int pHSensorPin = A0;    // Analog pin connected to the pH sensor
String cropType = "wheat";     // Change this to your crop of choice

String generateRecommendation(float pH, const String& crop);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pHSensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert ADC value to voltage
  float pHValue = -5.0 * voltage + 16.0;        // Example calibration formula

  String recommendation = generateRecommendation(pHValue, cropType);

  Serial.print("pH Value: ");
  Serial.println(pHValue);
  Serial.print("Recommendation: ");
  Serial.println(recommendation);

  delay(2000);
}

String generateRecommendation(float pH, const String& crop) {
  if (crop == "wheat") {
    if (pH < 6.5) return "Add nitrogen-rich fertilizer.";
    if (pH > 7.5) return "Soil is too alkaline, reduce lime.";
    return "Soil is optimal for wheat.";
  } else if (crop == "rice") {
    if (pH < 6.0) return "Add phosphorus-rich fertilizer.";
    if (pH > 7.0) return "Soil is too alkaline, consider manure.";
    return "Soil is optimal for rice.";
  }
  return "Crop not supported.";
}

