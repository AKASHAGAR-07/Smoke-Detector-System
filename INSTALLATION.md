# Installation & Setup Guide

This guide provides step-by-step instructions for assembling the hardware components and configuring the software environment for the **Smoke Detector System**.

---

## 1. Hardware Setup & Wiring

The system uses a **NodeMCU ESP8266** (or standard Arduino Uno) as the central processing unit. The wiring connections for all modules are detailed below.

### Pin Mapping Table

| Component | Pin Name | NodeMCU Pin | Arduino Pin | Description |
| :--- | :--- | :--- | :--- | :--- |
| **MQ-2 Gas Sensor** | VCC | 5V / Vin | 5V | Power supply (5V) |
| | GND | GND | GND | Ground reference |
| | A0 | A0 | A0 | Analog voltage representation of PPM |
| | D0 | D2 / GPIO4 | D7 | Digital threshold trigger (Optional) |
| **I2C 16x2 LCD** | VCC | 5V / Vin | 5V | Power supply (5V) |
| | GND | GND | GND | Ground reference |
| | SDA | D2 / GPIO4 | A4 | I2C Data Line |
| | SCL | D1 / GPIO5 | A5 | I2C Clock Line |
| **Buzzer** | Positive (+) | D8 / GPIO15 | D8 | High alarm trigger (Active High) |
| | Negative (-) | GND | GND | Ground reference |
| **Green LED** | Anode (+) | D6 / GPIO12 | D6 | Continuous power/safe state indicator |
| | Cathode (-) | GND (via 220Ω) | GND (via 220Ω) | Ground reference (through current limiter) |
| **Red LED** | Anode (+) | D7 / GPIO13 | D7 | Alarm indicator (Active with Buzzer) |
| | Cathode (-) | GND (via 220Ω) | GND (via 220Ω) | Ground reference (through current limiter) |

### Wiring Instructions

1. **Breadboard Power Rails**:
   - Connect the NodeMCU `3V3`/`Vin` (or Arduino `5V`) pin to the positive (+) rail on the breadboard.
   - Connect the NodeMCU `GND` pin to the negative (-) rail on the breadboard.
2. **Sensor Connections**:
   - Insert the **MQ-2 Gas Sensor** onto the breadboard. Connect its `VCC` pin to the `5V` power rail and `GND` to the ground rail. Connect the `A0` pin to `A0` on the microcontroller.
3. **LCD Connections**:
   - Attach the I2C interface module to the **16x2 LCD**.
   - Connect the LCD `VCC` to the `5V` rail, `GND` to the ground rail, `SDA` to the SDA pin (`D2` on NodeMCU, `A4` on Uno), and `SCL` to the SCL pin (`D1` on NodeMCU, `A5` on Uno).
4. **Indicators & Alarm Connections**:
   - Insert the **Buzzer** and **LEDs** on the breadboard.
   - Wire the Green LED anode to pin `D6` and cathode through a 220Ω resistor to ground.
   - Wire the Red LED anode to pin `D7` and cathode through a 220Ω resistor to ground.
   - Connect the Buzzer positive terminal to pin `D8` and negative terminal to ground.

---

## 2. Software Configuration

The project is programmed using the **Arduino IDE**. Follow these steps to configure your environment:

### Step 1: Install Arduino IDE
Download and install the latest version of the [Arduino IDE](https://www.arduino.cc/en/software).

### Step 2: Install Board Manager (For NodeMCU)
If you are using NodeMCU ESP8266:
1. Open Arduino IDE and go to **File > Preferences**.
2. Enter the following URL into the **Additional Boards Manager URLs** field:
   `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
3. Go to **Tools > Board > Boards Manager...**, search for `esp8266` by **ESP8266 Community**, and click **Install**.
4. Set your target board via **Tools > Board > ESP8266 Boards > NodeMCU 1.0 (ESP-12E Module)**.

### Step 3: Install Required Libraries
The code requires the `LiquidCrystal_I2C` library for managing the display:
1. Go to **Sketch > Include Library > Manage Libraries...**
2. Search for `LiquidCrystal I2C` by **Frank de Brabander** and click **Install**.
3. (Optional) The `Wire.h` library is included by default in the Arduino core.

### Step 4: Compile & Upload
1. Open the project code located in [Smoke_Detector.ino](CODE/Smoke_Detector.ino) within Arduino IDE.
2. Connect your NodeMCU/Arduino board to your PC via a USB cable.
3. Choose the appropriate COM port under **Tools > Port**.
4. Click the **Verify** button (check mark icon) to compile the code.
5. Once compiled successfully, click the **Upload** button (arrow icon) to program the board.
6. Open the **Serial Monitor** (**Tools > Serial Monitor**) at **9600 baud** to view real-time debug outputs.
