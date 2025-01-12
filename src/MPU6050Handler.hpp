#ifndef MPU6050HANDLER_HPP
#define MPU6050HANDLER_HPP

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

/**
 * @class MPU6050Handler
 * @brief A class to manage initialization, reading, and processing of data from the MPU6050 sensor.
 */
class MPU6050Handler {
public:
    /**
     * @brief Constructor for the MPU6050Handler class.
     *        Initializes the MPU6050 object.
     */
    MPU6050Handler();

    /**
     * @brief Initializes the MPU6050 sensor.
     *        Configures the accelerometer range, gyro range, and filter bandwidth.
     * @throws If the MPU6050 sensor is not detected, the function halts execution.
     */
    void initialize();

    /**
     * @brief Reads the current sensor data (acceleration, gyro, and temperature) and prints it to the Serial Monitor.
     */
    void readAndPrintSensorData();

private:
    Adafruit_MPU6050 mpu; ///< Instance of the Adafruit_MPU6050 class for interacting with the sensor.

    /**
     * @brief Prints the accelerometer data to the Serial Monitor.
     * @param a The acceleration sensor event containing x, y, and z values.
     */
    void printAcceleration(sensors_event_t& a);

    /**
     * @brief Prints the gyroscope data to the Serial Monitor.
     * @param g The gyro sensor event containing x, y, and z values.
     */
    void printGyro(sensors_event_t& g);

    /**
     * @brief Prints the temperature data to the Serial Monitor.
     * @param temp The temperature sensor event containing the temperature in degrees Celsius.
     */
    void printTemperature(sensors_event_t& temp);
};

#endif // MPU6050HANDLER_HPP
