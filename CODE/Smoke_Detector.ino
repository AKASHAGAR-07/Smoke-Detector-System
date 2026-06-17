/**
 * @file Smoke_Detector.ino
 * @brief IoT-Based Smoke Detection and Fire Safety Monitoring System.
 * @details This firmware reads gas concentration values from an MQ-2 sensor,
 *          displays the levels on a 16x2 I2C LCD, and triggers alarms (LED and Buzzer)
 *          when smoke or gas levels exceed the predefined safety thresholds.
 * 
 * Hardware Platform: NodeMCU ESP8266 / Arduino Uno
 * 
 * Team Members:
 *  - Akash V
 *  - Arun Pranav S K
 *  - Devanand N
 *  - Manoj S
 * 
 * Institution: Dr. N.G.P. Institute of Technology
 * Department of Electronics and Communication Engineering
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ==========================================
// PIN CONFIGURATION & HARDWARE ASSIGNMENTS
// ==========================================
const int MQ2_PIN = A0;              // Analog input pin for MQ-2 smoke sensor
const int BUZZER_PIN = 8;            // Digital output pin for buzzer alarm
const int LED_SAFE_PIN = 6;          // Digital output pin for green LED (safe indicator)
const int LED_ALARM_PIN = 7;         // Digital output pin for red LED (alarm indicator)

// ==========================================
// SYSTEM THRESHOLDS & CALIBRATION PARAMETERS
// ==========================================
const int GAS_THRESHOLD_SMOKE = 300; // Threshold above which smoke/gas is detected (PPM approximation)
const int GAS_THRESHOLD_FIRE = 750;  // Critical threshold indicating fire hazard
const int DEBOUNCE_DELAY_MS = 500;   // Delay between successive readings for stabilization

// Initialize the 16x2 I2C LCD (I2C address 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Initialize serial communication for diagnostic output
    Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial port to connect (needed for native USB boards)
    }
    Serial.println("=================================================");
    Serial.println("         SMOKE DETECTOR SYSTEM INITIALIZING      ");
    Serial.println("=================================================");

    // Configure microcontroller pins
    pinMode(MQ2_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_SAFE_PIN, OUTPUT);
    pinMode(LED_ALARM_PIN, OUTPUT);

    // Initial hardware states
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_ALARM_PIN, LOW);
    digitalWrite(LED_SAFE_PIN, HIGH); // Green LED on to indicate system power is active

    // Initialize 16x2 I2C Liquid Crystal Display
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.clear();
    
    // Boot splash screen
    lcd.setCursor(0, 0);
    lcd.print("   SYS START    ");
    lcd.setCursor(0, 1);
    lcd.print("Initializing...");
    
    delay(2000); // Allow sensor heater to warm up and stabilize
    lcd.clear();
}

void loop() {
    // Read raw analog signal from MQ-2 sensor
    int gasLevel = analogRead(MQ2_PIN);

    // Print diagnostic readings to the Serial Monitor
    Serial.print("[SENSOR DATA] Raw Gas Level Value: ");
    Serial.println(gasLevel);

    // Update First Line of LCD: Always display raw sensor value
    lcd.setCursor(0, 0);
    lcd.print("Gas Level: ");
    lcd.print(gasLevel);
    lcd.print("   "); // Trailing spaces clear artifact characters on display updates

    // Evaluate Gas Level against thresholds to execute alert routines
    if (gasLevel > GAS_THRESHOLD_FIRE) {
        // --- EMERGENCY FIRE ALERT LEVEL ---
        // Exceeds heavy smoke/combustion threshold
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_ALARM_PIN, HIGH);
        digitalWrite(LED_SAFE_PIN, LOW); // Turn off normal indicator

        Serial.println("[CRITICAL ALARM] Fire alert! Heavy smoke detected!");

        lcd.setCursor(0, 1);
        lcd.print("WARNING! FIRE   "); // Output hazard message to LCD Line 2
        
    } else if (gasLevel > GAS_THRESHOLD_SMOKE) {
        // --- SMOKE DETECTED WARNING LEVEL ---
        // Exceeds light smoke threshold
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(LED_ALARM_PIN, HIGH);
        digitalWrite(LED_SAFE_PIN, LOW);

        Serial.println("[WARNING] Smoke concentration exceeded safety threshold.");

        lcd.setCursor(0, 1);
        lcd.print("Smoke Detected! "); // Output caution message to LCD Line 2
        
    } else {
        // --- SAFE CONCENTATION / NORMAL ENVIRONMENT LEVEL ---
        // Sensor reading is within safe limits
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(LED_ALARM_PIN, LOW);
        digitalWrite(LED_SAFE_PIN, HIGH); // Re-engage green safe indicator

        Serial.println("[INFO] Gas concentration normal. Environment Safe.");

        lcd.setCursor(0, 1);
        lcd.print("Environment Safe"); // Output status message to LCD Line 2
    }

    // Delay before repeating the logic loop
    delay(DEBOUNCE_DELAY_MS);
}
