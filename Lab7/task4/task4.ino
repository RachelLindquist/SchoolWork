
#include <Zumo32U4.h>
void adjustDirection(int x){
  Zumo32U4Motors motors;

 motors.setSpeeds(100, -100);
 delay(21*x); // Don
 motors.setSpeeds(0,0);
 //Spin the robot counter-clockwise
 motors.setSpeeds(-100, 100);
 delay(17*x);
 motors.setSpeeds(0,0);
}
void setup() {
 adjustDirection(90);
}
void loop() {
 
}
