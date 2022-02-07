//load libs and headers ----------------------------------------------------------------------------------//
#include <IBusBM.h> // these are libs
#include <ESP32Servo.h> 
#include "settings.h" // these are headers
#include "ibus_function.h"
#include "motor_functions.h"


// SETUP Controller -------------------------------------------------------------------------------------//
void setup() {
  // put your setup code here, to run once:
  // Start serial monitor for debug
  Serial.begin(115200);
  // Attach iBus object to serial port
  ibus.begin(Serial2);
  Setup_MPins();
}

void loop() {
  
Ibus_Read(); //read Ibus 
Debug_plot_raw(0);// turn on ibus debug on Serial0 

// do motor control here 
Tank_Drive(CC[1],CC[3]);

}
