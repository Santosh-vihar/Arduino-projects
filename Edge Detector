#include <AFMotor.h>  // Adafruit Motor Shield Library

AF_DCMotor motor1(1);  // Motor M1
AF_DCMotor motor2(2);  // Motor M2
AF_DCMotor motor3(3);  // Motor M3
AF_DCMotor motor4(4);  // Motor M4

#define IR_LEFT 9   // Left IR sensor (Digital Pin)
#define IR_RIGHT 10 // Right IR sensor (Digital Pin)

void setup() {
    pinMode(IR_LEFT, INPUT);
    pinMode(IR_RIGHT, INPUT);
    
    Serial.begin(9600);
    
    // Set initial speed (0-255)
    motor1.setSpeed(150);
    motor2.setSpeed(150);
    motor3.setSpeed(150);
    motor4.setSpeed(150);
}

void moveForward() {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void moveBackward() {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void stopBot() {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void turnLeft() {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(FORWARD);
}

void turnRight() {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
}

void loop() {
    int leftSensor = digitalRead(IR_LEFT);
    int rightSensor = digitalRead(IR_RIGHT);

    Serial.print("Left Sensor: ");
    Serial.print(leftSensor);
    Serial.print(" | Right Sensor: ");
    Serial.println(rightSensor);

    if (leftSensor == 0 && rightSensor == 0) {
        moveForward();  // Move forward if no edge is detected
    } 
    else if (leftSensor == 1 && rightSensor == 0) {
        turnRight();  // Turn right if left sensor detects an edge
        delay(500);
    } 
    else if (leftSensor == 0 && rightSensor == 1) {
        turnLeft();  // Turn left if right sensor detects an edge
        delay(500);
    } 
    else {
        // If both sensors detect an edge:
        moveBackward();  // Move backward
        delay(700);      // Adjust for better reversing
        turnRight();     // Turn right
        delay(500);      // Adjust for a smooth turn
        moveForward();   // Move forward after turning
    }

    delay(100);
}
