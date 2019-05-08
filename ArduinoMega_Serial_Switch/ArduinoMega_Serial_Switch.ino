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
int whichPort = 1;

// Code ---------------------------------------------------
void setup() 
{
  delay(500);
  // Begin the Arduino <-> PC serial communication
  Serial.begin(BAUD_RATE_COMPUTER_INTERFACE);
  Serial.println("System ON");

  // Get the serial baud rates for the other devices
  long deviceBaudRate = 0;
  // Device 1
  Serial.print("Serial baud rate for device 1:\t");
  while(Serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial1.begin(deviceBaudRate);
  Serial.println(deviceBaudRate);
  while(Serial.available()>0)
    {
      Serial.read();
    }

  // Device 2
  Serial.print("Serial baud rate for device 2:\t");
  while(Serial.available()==0){} 
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial2.begin(deviceBaudRate);
  Serial.println(deviceBaudRate);
  while(Serial.available()>0)
  {
      Serial.read();
  }

  // Device 3
  Serial.print("Serial baud rate for device 3:\t");
  while(Serial.available()==0){}
  delay(10);
  deviceBaudRate = Serial.parseInt();
  Serial3.begin(deviceBaudRate);
  Serial.println(deviceBaudRate);
  while(Serial.available()>0)
  {
      Serial.read();
  }

  // Enter main loop
  Serial.println("Enter Main Loop: Press number corresponding to device to switch which device is reported");
  delay(1000);
}

void loop() 
{
  // Check for change 
  if(Serial.available()>0)
  {
    long temp = Serial.parseInt();
    delay(50);
    while(Serial.available()>0)
    {
      Serial.read();
    }
    // Only accept valid inputs
    if((temp==1)||(temp==2)||(temp==3))
    {
      if(temp!=whichPort)
      {
        whichPort = temp;
        Serial.println("-------------------------------------------------------");
        Serial.print("Switch to device "); Serial.println(whichPort);
        Serial.println("-------------------------------------------------------");
      }
    }
    else
    {
      Serial.println("Invalid port specified");
    }
  }

  // Report based on which serial port
  switch(whichPort)
  {
    case 1:
      while(Serial1.available()>0)
      {
        Serial.write(Serial1.read());
      }
    break;

    case 2:
      while(Serial2.available()>0)
      {
        Serial.write(Serial2.read());
      }
    break;

    case 3:
      while(Serial3.available()>0)
      {
        Serial.write(Serial3.read());
      }
    break;

    default:
      Serial.print("Invalid device specified: "); Serial.println(whichPort);
      delay(500);
    break;
  }

}
