#include <Arduino.h>
#include "MPU6050Handler.hpp"

// Create an instance of the MPU6050Handler class to manage the sensor.
MPU6050Handler mpuHandler;

void setup() {
    // Initialize the Serial communication for debugging and output.
    Serial.begin(115200);

    // Initialize the MPU6050 sensor. If it fails, the program will halt.
    mpuHandler.initialize();
}

void loop() {
    // Read sensor data (acceleration, gyroscope, temperature) and print it to the Serial Monitor.
    mpuHandler.readAndPrintSensorData();

    // Wait for 500 milliseconds before the next sensor read.
    delay(500);
}
