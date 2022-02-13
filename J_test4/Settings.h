
// define GPIO pins for motor control
#define RPWM0 12
#define LPWM0 13
#define RPWM1 18
#define LPWM1 19
#define REN0 22
#define LEN0 23
#define CMin 1000
#define CMax 1000
#define MMin -255
#define MMax 255
//#define PWM 11 // for scotts code
#define BusArray_size 7 // change this for CC size you have 
int CC[BusArray_size]; // define the Control Channal int array 
//#define DEBUGIBUS
//#define DEBUGDRIVE
