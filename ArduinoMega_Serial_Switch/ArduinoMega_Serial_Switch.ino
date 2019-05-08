/*/////////////////////////////////////////////////////////
Author:       Petras Swissler
Date Created: 2019-05-08

Description:  Simple sketch to allow Arduino Mega to 
              Switch between different serial ports

TODO:         Enable sending RX to the serial ports
              Enable baseline functionailty
/////////////////////////////////////////////////////////*/
// Definitions and Variables ------------------------------
#define BAUD_RATE_COMPUTER_INTERFACE    115200
int whichPort = '1';

// Code ---------------------------------------------------
void setup() 
{
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
  Serial.println(deviceBaudRate);

  // Device 2
  Serial.print("Serial baud rate for device 2:\t");
  while(serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial2.begin(deviceBaudRate);
  Serial.println(deviceBaudRate);

  // Device 3
  Serial.print("Serial baud rate for device 3:\t");
  while(serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial3.begin(deviceBaudRate);
  Serial.println(deviceBaudRate);

  // Enter main loop
  Serial.println("Enter Main Loop: Press number corresponding to device to switch which device is reported");
  delay(1000)
}

void loop() 
{
  // Check for change 
  if(Serial.available()>0)
  {
    whichPort = Serial.read();
    while(Serial.available()>0)
    {
      Serial.read();
    }
    Serial.println("-------------------------------------------------------");
    Serial.print("Switch to device "); Serial.print(whichPort);
    Serial.println("-------------------------------------------------------");
  }

  // Report based on which serial port
  switch(whichPort)
  {
    case '1':
      while(Serial1.available()>0)
      {
        Serial.print(Serial1.read());
      }
    break;

    case '2':
      while(Serial2.available()>0)
      {
        Serial.print(Serial2.read());
      }
    break;

    case '3':
      while(Serial3.available()>0)
      {
        Serial.print(Serial3.read());
      }
    break;

    default:
      Serial.print("Invalid device specified: "); Serial.print(whichPort);
    break;
  }

}
