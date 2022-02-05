//load libs --------------------------------------------------------------------------------------------//
#include <IBusBM.h>
#include <ESP32Servo.h>

// define GPIO pins for motor control
#define RPWM 12
#define LPWM 13
#define REN 22
#define LEN 23
//#define PWM 11 // for scotts code
#define BusArray_size 10 // change this for ibus size you have 
int CC[BusArray_size]; // define the array

// Create iBus Object
IBusBM ibus;
// Make functions -------------------------------------------------------------------------------------//
// TODO: Move to lib later 
// <----- IBus functions ----->
// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value 
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}


void Debug_plot_raw(int Com){
   for (byte i = 0; i < BusArray_size; i = i + 1) {
      Serial.print (CC[i]);
      Serial.print(" ");
   }
    Serial.println(" ");
   
}
void Ibus_Read(){
  for (byte i = 0; i < BusArray_size; i = i + 1) {
      CC[i] = ibus.readChannel(i);
  }
}
  
// Read the channel and return a boolean value
// My controler has 3 position switchs TODO: Mod this to int or make 3way switch func
bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}

// <----- bts7960 functions ----->

//clockwise
void motor_cw(int value) {
  digitalWrite (LPWM, LOW);
  analogWrite (RPWM, value);  //for scotts motor style change digitalWrite (RPWM, High);
  // 0-255
  //analogWrite (PWM, value); //for scotts motor style
  //Serial.println ("Running clockwise"); //debug on 
}

//counter clockwise
void motor_ccw(int value) { 
  analogWrite (LPWM, value*-1); //for scotts motor style change digitalWrite (LPWM, High);
  digitalWrite (RPWM, LOW);
  // multiply speed value by -1 so motorcontroller gets a positive speed value
  //analogWrite (PWM, value*-1); //for scotts motor style
  // Serial.println ("Running counter clockwise"); //debug on

// motor stop
}
void motor_stop() { 
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, LOW);
  //analogWrite (PWM, 0); //for scotts motor style
  //Serial.println ("Stopped");  //debug on
}
// SETUP Controller -------------------------------------------------------------------------------------//
void setup() {
  // put your setup code here, to run once:
 // Start serial monitor for debug
Serial.begin(115200);
//Serial.println("Start motor control");

  // Attach iBus object to serial port
  ibus.begin(Serial2);

//Assign pins for motor controler numbered..
pinMode (RPWM, OUTPUT);
pinMode (LPWM, OUTPUT);
pinMode(LEN,OUTPUT);
pinMode(REN,OUTPUT);
digitalWrite(REN,HIGH);
digitalWrite(LEN,HIGH);
//pinMode (PWM, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // this is where we read the channel data: ch#, min, max, and ?. I don't fully understand this yet.
  // previous: int value = readChannel(0, -100, 100, 0);
  // experimenting with int value = readChannel(0, -255, 255, 0);

Ibus_Read();
Debug_plot_raw(0);
  
int value = readChannel(0, -255, 255, 0);
if (value > 0){
  motor_cw(value);
  //Serial.println (value);
  delay (10);
}
else if (value < 0) {
  motor_ccw(value);
  //Serial.println (value);
  delay (10);
}
else {
  motor_stop();
}
}
