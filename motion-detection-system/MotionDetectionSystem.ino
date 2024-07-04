#include <Wire.h>
#include <SoftwareSerial.h>

// Define pin numbers
const int pirPin = 2;    // Digital pin for PIR sensor
const int buzzerPin = 3; // Digital pin for buzzer
const int ledPin = 4;    // Digital pin for LED

// Initialize software serial for GSM communication
SoftwareSerial gsm_serial(9,10); // RX, TX pins for GSM module

void setup() {
  // Initialize serial communication
  Serial.begin(9600); // Serial monitor baud rate
  gsm_serial.begin(9600); // GSM module baud rate

  // Initialize pins
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("System Initialized");
}

void loop() {
  // Check for motion using PIR sensor
  int pirValue = digitalRead(pirPin);
  Serial.print("Motion detected: ");
  Serial.println(pirValue);

  // If motion detected
  if (pirValue == HIGH) {
    // Sound the buzzer
    tone(buzzerPin, 3000); // Adjust frequency as needed
    delay(1000); // Sound for 2 seconds
    noTone(buzzerPin);

    // Turn on LED
    digitalWrite(ledPin, HIGH);
    delay(1000); // Adjust this delay according to your needs
    digitalWrite(ledPin, LOW);

    // Send alert
    checkAndSendAlert(pirValue);
  }

  // Add some delay to avoid rapid readings
  delay(500);
}

// Function to check sensor values and send an alert if needed
void checkAndSendAlert(int value) {
  // If the condition is met, send an SMS alert
  if (value == HIGH) {
    char alertMessage[100];
    snprintf(alertMessage, sizeof(alertMessage), "Alert: Motion detected!");
    sendSMS(alertMessage);
  }
}

// Function to send an SMS message
void sendSMS(const char* message) {
  Serial.println("Sending Message");
  gsm_serial.println("AT+CMGF=1"); // Sets the GSM Module in Text Mode
  delay(1000);
  gsm_serial.println("AT+CMGS=\"+94711945184\"\r"); // Replace with your phone number
  delay(1000);
  gsm_serial.println(message);
  Serial.println(message);
  delay(100);
  gsm_serial.println((char)26); // ASCII code of CTRL+Z
  delay(1000);
}
