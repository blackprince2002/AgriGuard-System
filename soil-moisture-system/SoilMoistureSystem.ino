#include <Wire.h>
#include <SoftwareSerial.h>

// Define pin numbers
const int soilMoisturePin1 = A0;   // Analog pin for soil moisture sensor 1
const int soilMoisturePin2 = A1;   // Analog pin for soil moisture sensor 2
const int soilMoisturePin3 = A2;   // Analog pin for soil moisture sensor 3
const int soilMoisturePin4 = A3;   // Analog pin for soil moisture sensor 3


// Define thresholds
const int soilMoistureThreshold = 500;  // Adjust this value according to your soil moisture sensor

// Motor control pins and settings
int mainMotorIN1 = 12;
int mainMotorIN2 = 13;

void setup() {
  // Initialize serial communication
  Serial.begin(9600); // Adjust baud rate as needed
  
  // Initialize pins
  pinMode(soilMoisturePin1, INPUT);
  pinMode(soilMoisturePin2, INPUT);
  pinMode(soilMoisturePin3, INPUT);
  pinMode(soilMoisturePin4, INPUT);
  pinMode(mainMotorIN1, OUTPUT);
  pinMode(mainMotorIN2, OUTPUT);
  
}

void loop() {
  // Read soil moisture sensor values and calculate the average
  int AvgsoilMoistureValue = (analogRead(soilMoisturePin1) + analogRead(soilMoisturePin2) + analogRead(soilMoisturePin3)+analogRead(soilMoisturePin4)) / 4;
  Serial.print("Soil Moisture: ");
  Serial.println(AvgsoilMoistureValue);

  // Check if soil moisture is below threshold
  if (AvgsoilMoistureValue > soilMoistureThreshold) {
    // Start watering
    digitalWrite(mainMotorIN1, HIGH);
    //delay(1000); // Adjust this delay according to your watering needs 
    digitalWrite(mainMotorIN2, LOW);
    delay(1000);
  }
  else{
     digitalWrite(mainMotorIN1, LOW);
    //delay(1000); // Adjust this delay according to your watering needs
    digitalWrite(mainMotorIN2, LOW);
  }

  // Add some delay to avoid rapid readings
  delay(500);
}
