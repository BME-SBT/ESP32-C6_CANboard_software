# ESP32-C6_CANboard_software Install HOW TO 
## 1. Lépés:
Telepíts egy Visual Studio Code-ot innen: 
https://code.visualstudio.com/download

## 2. Lépés:
A bal oldali menüben keresd meg az extensions fület. Ezt követően kezd el gépelni, hogy ESP és az ESP-IDF csomagot töltsd le az install gombra kattintva.
![howto1](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/cb909abd-479e-4cec-9e58-40f5526f151d)


## 3. Lépés:
Kattints a most megjelent bal oldali menüben az IDF ikonjára. A következő képernyő fogad ilyenkor. Itt kattints az EXPRESS feliratra. 
![howto2](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/292aa70f-5628-43b6-8980-4faa37b8b773)


## 4. Lépés:
Válaszd ki az IDF verziót. Ide a v5.2 (release version)-t ajánlom. Majd mehet az Install.
Itt még kiválaszthatod hova szeretnéd telepíteni, ha esetleg nem az automatikusan választott mappába. 
![howto3](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/9420a074-40b0-4d65-ae11-d3bf891ecf82)


## 5. Lépés:
Ha a telepít lefutott hozzunk létre egy új projektet. 
Ehhez kattintsunk a New Project gombra majd válasszuk ki, hogy milyen típusú 
ESP eszközre szeretnénk fejleszteni és hogy az melyik COM porton található. 
A COM porthoz Windows-on az Eszközkezelő menübe kell belépni és ott megkeresni a csatlakoztatott eszközt. 
![howto4](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/390fc49b-c91e-40f7-a0a4-d6077d85098c)


## 6. Lépés:
A bal oldali legördülő menüből válasszuk ki az ESP-IDF opciót majd keressünk egy szimpatikus már létező templatet.
![howto5](https://github.com/BME-SBT/ESP32-C6_CANboard_software/assets/79412599/fcb84034-29d1-4d89-8a47-d9700b925d6d)


## 7. Lépés:
A VSCode alján található menüvel a kis láng ikonnal buld-elhetjük és flash-elhetjük egy lépésben a projektet. Ehhez megkérdezi a környezet, hogy min keresztül akaruk a flash-t. Itt az UART a legegyszerbb opció számunkra. 

## 8. Lépés:
Be happy! Működik a környezet és már dolgozhatsz is a projekten <3
