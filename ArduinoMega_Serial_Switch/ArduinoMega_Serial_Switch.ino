/*/////////////////////////////////////////////////////////
Author:       Petras Swissler
Date Created: 2019-05-08

Description:  Simple sketch to allow Arduino Mega to 
              Switch between different serial ports

TODO:         Enable sending RX to the serial ports
              Enable baseline functionailty
/////////////////////////////////////////////////////////*/
// Definitions --------------------------------------------
#define BAUD_RATE_COMPUTER_INTERFACE    115200

// Code ---------------------------------------------------
void setup() {
  // Begin the Arduino <-> PC serial communication
  Serial.begin(BAUD_RATE_COMPUTER_INTERFACE);
  Serial.println("System ON");

  // Get the serial baud rates for the other devices
  long deviceBaudRate = 0;
  // Device 1
  Serial.print("Serial baud rate for device 1:\t");
  while(serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial1.begin(deviceBaudRate);
  Serial.print(deviceBaudRate);

  // Device 2
  Serial.print("Serial baud rate for device 2:\t");
  while(serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial2.begin(deviceBaudRate);
  Serial.print(deviceBaudRate);

  // Device 3
  Serial.print("Serial baud rate for device 3:\t");
  while(serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial3.begin(deviceBaudRate);
  Serial.print(deviceBaudRate);

}

void loop() {
  // put your main code here, to run repeatedly:

}
