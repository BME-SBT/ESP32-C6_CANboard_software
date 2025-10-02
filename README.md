# ESP32-C6_CANboard_software Install HOW TO 
## 1. Step:
Install visual studio code from this link: 
https://code.visualstudio.com/download

## 2. Step:
In the left menu bar find the option "extensions". Start typing esp and install ESP-IDF.
![howto1](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/cb909abd-479e-4cec-9e58-40f5526f151d)


## 3. Step:
Find the esp icon on the left side and press it. After you click on the esp button select EXPRESS installation. 
![howto2](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/292aa70f-5628-43b6-8980-4faa37b8b773)


## 4. Step:
Select the ESP-IDF version (I recommend selecting the release version), after that if you would like to, now you can change the destination folder, after that click on install.
![howto3](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/9420a074-40b0-4d65-ae11-d3bf891ecf82)


## 5. Step:
After the installation has finished create a new project, tzpe in the project name and select the destination folder. For the IDF target choose ESP32-C6 and for the ESP-IDF Board choose ESP32-C6 chip (via builtin USB-JTAG). After that select your serial port and click on choose template.
![howto4](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/390fc49b-c91e-40f7-a0a4-d6077d85098c)


## 6. Step:
Either choose template-app or select ESP-IDF from the dropp down menu and choose the right project for you. (most of the time we will be working from the template-app)
![howto5](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/fcb84034-29d1-4d89-8a47-d9700b925d6d)


## 7. Step:
In the "open project" pop up window choose yes, after that your project will open automatically in a new tab. You can build, flash and monitor your project with the flame button in the bottom left. (I recommend pressing build after the first time you launch the project, because the first build takes a few minutes)

## 8. Step:
Be happy! Your enviroment works and you can start working on your first esp32 project <3

## Bonus Step:
ESP TOOL: https://espressif.github.io/esptool-js/
ESP API REFFERENCE: https://docs.espressif.com/projects/esp-idf/en/v5.5.1/esp32c6/api-reference/index.html


