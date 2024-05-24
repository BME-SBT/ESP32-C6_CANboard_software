#include <ESP32-TWAI-CAN.hpp>
#include <SoftwareSerial.h>

#include "sensor.h"

// Default for ESP32
#define CAN_TX		16
#define CAN_RX		17

SoftwareSerial motor_serial(3, 4);

Sensor<uint16_t> s_motor_rpm(0b00001010010, 10);
Sensor<uint16_t> s_motor_current(0b01111110010, 10);
Sensor<uint16_t> s_motor_temp(0b00010110010, 10);
Sensor<uint16_t> s_motor_controller_temp(0b00011010010, 10);
Sensor<int32_t> s_motor_power(0b10000110010, 10);
Sensor<int8_t> s_throttle_position(0b00000010101, 10);

void dump_bytes(uint8_t *ptr, size_t size)
{
    for (size_t pos = 0; pos < size; pos++)
    {
        if (ptr[pos] < 0x10)
            Serial.print('0');
        Serial.print(ptr[pos], HEX);
        Serial.print(' ');
        if ((pos + 1) % 16 == 0)
            Serial.println();
    }
    Serial.println();
}

void setup()
{
    // USB debugging
    Serial.begin(115200);

    ESP32Can.setPins(CAN_TX, CAN_RX);

    // CAN init
    if (!ESP32Can.begin(ESP32Can.convertSpeed(500))) {
        Serial.println("Starting CAN failed!");
        while (1) {
            delay(100);
        }
    }

    // Motor UART init
    motor_serial.begin(19200);
    pinMode(3, INPUT);
    pinMode(4, OUTPUT);

}

float motor_voltage = 0.0f;
bool success = false;
static uint8_t motor_data_raw[47];

void read_motor_data()
{
    memset(motor_data_raw, 0, 45);
    motor_serial.write(0x80);
    motor_serial.write(0x8d);
    delay(5);
    // motor_serial.setTimeout(50);
    motor_serial.readBytes(motor_data_raw, 45);
    // dump_bytes(motor_data_raw, 45);

    if (motor_data_raw[0] == 0x7c && motor_data_raw[1] == 0x8d)
    {
        if (motor_data_raw[43] == 0x7d)
        {
            success = true;
            int controller_temp = motor_data_raw[16] - 20;
            int motor_temp = motor_data_raw[17] - 20;
            int rpm = ((motor_data_raw[22] << 8) | motor_data_raw[21]) * 10;
            float current = ((motor_data_raw[29] << 8) | motor_data_raw[28]) / 10.0;
            motor_voltage = ((motor_data_raw[31] << 8) | motor_data_raw[30]) / 10.0;
            int throttle_pos = motor_data_raw[35];
            
            s_motor_controller_temp.set_value(controller_temp);
            s_motor_temp.set_value(motor_temp);
            s_motor_rpm.set_value(rpm);
            s_motor_current.set_value(current);
            s_throttle_position.set_value(throttle_pos);
        }
    }
}

void loop()
{
    read_motor_data();
    if (success)
    {
        s_motor_controller_temp.send();
        s_motor_temp.send();
        s_motor_rpm.send();
        s_motor_current.send();
        s_throttle_position.send();
        success = false;
    }
    delay(100);
}
