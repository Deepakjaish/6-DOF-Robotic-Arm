#include <Servo.h>

Servo Shoulder;
Servo Wrist_2;
Servo Gripper;

// Current positions
int ShoulderPos = 1500;
int Wrist2Pos = 1500;
int GripperPos = 1500;

// Movement states
bool shoulderForward = false;
bool shoulderBackward = false;

bool wristForward = false;
bool wristBackward = false;

bool gripperOpen = false;
bool gripperClose = false;

void setup() {

  Shoulder.attach(5);
  Wrist_2.attach(9);
  Gripper.attach(11);

  Shoulder.writeMicroseconds(ShoulderPos);
  Wrist_2.writeMicroseconds(Wrist2Pos);
  Gripper.writeMicroseconds(GripperPos);

  Serial.begin(9600);
}

void loop() {

  // Receive command from PC
  if (Serial.available() > 0) {

    char command = Serial.read();

    // ---------------- SHOULDER ----------------

    if (command == 'F') {
      shoulderForward = true;
      shoulderBackward = false;
    }

    else if (command == 'B') {
      shoulderBackward = true;
      shoulderForward = false;
    }

    else if (command == 'X') {
      shoulderForward = false;
      shoulderBackward = false;
    }


    // ---------------- WRIST 2 ----------------

    else if (command == 'W') {
      wristForward = true;
      wristBackward = false;
    }

    else if (command == 'S') {
      wristBackward = true;
      wristForward = false;
    }

    else if (command == 'Y') {
      wristForward = false;
      wristBackward = false;
    }


    // ---------------- GRIPPER ----------------

    else if (command == 'G') {
      gripperOpen = true;
      gripperClose = false;
    }

    else if (command == 'H') {
      gripperClose = true;
      gripperOpen = false;
    }

    else if (command == 'Z') {
      gripperOpen = false;
      gripperClose = false;
    }
  }


  // ---------------- MOVE SHOULDER ----------------

  if (shoulderForward && ShoulderPos < 2500) {
    ShoulderPos += 5;
    Shoulder.writeMicroseconds(ShoulderPos);
  }

  if (shoulderBackward && ShoulderPos > 1500) {
    ShoulderPos -= 5;
    Shoulder.writeMicroseconds(ShoulderPos);
  }


  // ---------------- MOVE WRIST 2 ----------------

  if (wristForward && Wrist2Pos < 2000) {
    Wrist2Pos += 5;
    Wrist_2.writeMicroseconds(Wrist2Pos);
  }

  if (wristBackward && Wrist2Pos > 1000) {
    Wrist2Pos -= 5;
    Wrist_2.writeMicroseconds(Wrist2Pos);
  }


  // ---------------- MOVE GRIPPER ----------------

  if (gripperOpen && GripperPos < 2000) {
    GripperPos += 5;
    Gripper.writeMicroseconds(GripperPos);
  }

  if (gripperClose && GripperPos > 1000) {
    GripperPos -= 5;
    Gripper.writeMicroseconds(GripperPos);
  }

  delay(20);
}