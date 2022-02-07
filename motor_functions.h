// <----- bts7960 functions ----->

/* think we want 1 function that includes all this in a mathamatical way IE 
 * clockwise
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

// motor stop maybe more of an motor enable?
}
void motor_stop() { 
  digitalWrite (LPWM, LOW);
  digitalWrite (RPWM, LOW);
  //analogWrite (PWM, 0); //for scotts motor style
  //Serial.println ("Stopped");  //debug on
}
*/

void Setup_MPins(){
  //Assign pins for motor controler numbered..
  pinMode (RPWM0, OUTPUT);
  pinMode (LPWM0, OUTPUT);
  pinMode(LEN0,OUTPUT); //enable left
  pinMode(REN0,OUTPUT); //enable right 
  digitalWrite(REN0,HIGH);
  digitalWrite(LEN0,HIGH);
  //pinMode (PWM, OUTPUT);
}

void Tank_Drive(int FB,int LR){// attach Control Chan for Forw/Bac and Lft/Rght
 int CFB = map(FB,1000,2000,-255,255); //clean for/bac and set 1500 to 0 for center stick 
 int CLR = map(LR,1000,2000,-255,255); //clean lft/rght and set 1500 to 0 for center stick

  //do Math
  int Lspeed = CFB+CLR;
  int Rspeed = CFB-CLR;
  //do More Math For BTS drive
  if(0 < Lspeed){
    digitalWrite (LPWM0, LOW);
    analogWrite (RPWM0, Lspeed);
  }
  else{
    analogWrite (LPWM0,Lspeed *-1); //for scotts motor style change digitalWrite (LPWM, High);
    digitalWrite (RPWM0, LOW);
  }
  if(0 < Rspeed){
    digitalWrite (LPWM1, LOW);
    analogWrite (RPWM1, Rspeed);
  }
  else{
    analogWrite (LPWM1, Rspeed *-1); //for scotts motor style change digitalWrite (LPWM, High);
    digitalWrite (RPWM1, LOW);
  }
}
