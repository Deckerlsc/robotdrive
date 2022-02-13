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
  
Ibus_Read(); //read 
#ifdef DEBUGIBUS
Debug_plot_raw(0);// turn on ibus debug on Serial0 
#endif
if(PowerSwitch(5)){ //turn on tankdrive my switch is on CC5 off is 1000 on is 2000
 Tank_Drive(CC[1],CC[3]);
 #ifdef DEBUGDRIVE
 Serial.print("drive on ");
 #endif
}
Serial.println (duelp3Switch(4));
}
