#include <Zumo32U4.h>
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
uint8_t  getProximity(void){
 
  proxSensors.read(); 
  
  Serial.println(proxSensors.countsFrontWithLeftLeds());
  Serial.println(proxSensors.countsFrontWithRightLeds());
  
  return (proxSensors.countsFrontWithRightLeds()+proxSensors.countsFrontWithLeftLeds())/2;

}
void setup() {
  proxSensors.initThreeSensors();
  motors.setSpeeds(100,100);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (getProximity() == 0){
    motors.setSpeeds(0,0);
  } else {
    motors.setSpeeds(100,100);
  }
  
}
