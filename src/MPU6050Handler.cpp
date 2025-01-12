#include "MPU6050Handler.hpp"

// Constructor: Initializes the Adafruit_MPU6050 instance.
MPU6050Handler::MPU6050Handler() : mpu() {}

// Initializes the MPU6050 sensor.
// Configures the accelerometer range, gyro range, and filter bandwidth.
// If the sensor is not detected, the program halts with an error message.
void MPU6050Handler::initialize() {
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) {
            delay(10); // Wait indefinitely for manual reset if initialization fails.
        }
    }
    Serial.println("MPU6050 Found!");

    // Set accelerometer range to ±8G.
    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

    // Set gyroscope range to ±500 degrees/second.
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);

    // Set the low-pass filter bandwidth to 21 Hz to reduce noise.
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

    delay(100); // Allow time for the sensor to stabilize.
}

// Reads data from the MPU6050 sensor and prints acceleration, gyroscope, and temperature values.
void MPU6050Handler::readAndPrintSensorData() {
    sensors_event_t acceleration, gyro, temperature;

    // Retrieve sensor events for acceleration, gyroscope, and temperature.
    mpu.getEvent(&acceleration, &gyro, &temperature);

    // Print the retrieved data.
    printAcceleration(acceleration);
    printGyro(gyro);
    printTemperature(temperature);

    Serial.println(""); // Add an empty line for readability.
}

// Prints the acceleration data (X, Y, Z) to the Serial Monitor.
void MPU6050Handler::printAcceleration(sensors_event_t& a) {
    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");
}

// Prints the gyroscope data (X, Y, Z) to the Serial Monitor.
void MPU6050Handler::printGyro(sensors_event_t& g) {
    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");
}

// Prints the temperature data to the Serial Monitor.
void MPU6050Handler::printTemperature(sensors_event_t& temp) {
    Serial.print("Temperature: ");
    Serial.print(temp.temperature);
    Serial.println(" degC");
}
