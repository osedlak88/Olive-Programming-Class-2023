/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Apr 19 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftM                motor         1               
// rightM               motor         2               
// Inertial3            inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void drive(int distance, int speed){
  rightM.resetRotation();
  rightM.setVelocity(speed, pct);
  leftM.setVelocity(speed, pct);
  int delta = distance - rightM.position(deg);

  while(abs(int(rightM.rotation(degrees))) < abs(distance)){
    speed = delta;
    rightM.spin(forward, speed, pct);
    leftM.spin(forward, speed, pct);
  }
  rightM.stop();
  leftM.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  drive(500, 100);
}
