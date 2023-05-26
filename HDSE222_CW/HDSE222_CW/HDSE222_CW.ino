#include <NewPing.h>

int ENA = 9;  //ENA connected to digital pin 3
int ENB = 10;  //ENB connected to digital pin 9
int MOTOR_A1 = 2; // MOTOR_A1 connected to digital pin 4
int MOTOR_A2 = 3; // MOTOR_A2 connected to digital pin 5
int MOTOR_B1 = 4; // MOTOR_B1 connected to digital pin 6
int MOTOR_B2 = 5; // MOTOR_B2 connected to digital pin 7

int RIGHT = 7; //for break light
int LEFT = 6;  //for break light

int PATH_DETECTOR = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(ENA, OUTPUT); // initialize ENA pin as an output
pinMode(ENB, OUTPUT); // initialize ENB pin as an output
pinMode(MOTOR_A1, OUTPUT); // initialize MOTOR_A1 pin as an output
pinMode(MOTOR_A2, OUTPUT); // initialize MOTOR_A2 pin as an output
pinMode(MOTOR_B1, OUTPUT); // initialize MOTOR_B1 pin as an output
pinMode(MOTOR_B2, OUTPUT); // initialize MOTOR_B2 pin as an output
pinMode(RIGHT, INPUT);//initializa RIGHT pin as an input for Right sensor
pinMode(LEFT, INPUT);//initializa LEFT pin as an input for Left sensor
pinMode(PATH_DETECTOR,INPUT);//initializa PATH_DETECTOR pin as an input for middle sensor
Serial.begin(9600);
}

void loop() {
  //110
  if(digitalRead(LEFT)==HIGH && digitalRead(PATH_DETECTOR)==HIGH && digitalRead(RIGHT)==LOW){
    Serial.println("turnRight");
    turnLeft();
    delay(80);
    //110
    }else if(digitalRead(RIGHT)==HIGH && digitalRead(PATH_DETECTOR)==HIGH && digitalRead(LEFT)==LOW){
      Serial.println("turnLeft");
      turnRight();
      delay(80);
      //111
      }else if(digitalRead(RIGHT)==HIGH && digitalRead(PATH_DETECTOR)==HIGH && digitalRead(LEFT)==HIGH){
        Serial.println("turnLeft");
      turnLeft();
      delay(80);
      //000
      }else if(digitalRead(RIGHT)==LOW && digitalRead(PATH_DETECTOR)==LOW && digitalRead(LEFT)==LOW){
        Serial.println("turnRight");
      turnRight();
      delay(80);
      //001
      }else if(digitalRead(RIGHT)==LOW && digitalRead(PATH_DETECTOR)==LOW && digitalRead(LEFT)==HIGH){
        Serial.println("turnLeft");
      turnLeft();
      delay(80);
      //100
      }else if(digitalRead(RIGHT)==HIGH && digitalRead(PATH_DETECTOR)==LOW && digitalRead(LEFT)==LOW){
        Serial.println("turnRight");
      turnRight();
      delay(80);
      //010
      }else if(digitalRead(RIGHT)==LOW && digitalRead(PATH_DETECTOR)==HIGH && digitalRead(LEFT)==LOW){
      Serial.println("moveForward");
      moveForward();
      }
  /*
  if(digitalRead(LEFT)== HIGH){
    Serial.println("LEFT DARK !");}else{Serial.println("LEFT LIGHT !");}
    delay(3000);

      if(digitalRead(RIGHT)== HIGH){
    Serial.println("RIGHT DARK !");}else{Serial.println("RIGHT LIGHT !");}
    delay(3000);
      if(digitalRead(PATH_DETECTOR)== HIGH){
    Serial.println("PD DARK !");}else{Serial.println("PD LIGHT !");}
    delay(3000);    */
 
}

void Stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_B2, LOW);

}

void turnRight() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(MOTOR_A1, HIGH);
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_B2, HIGH);
  
}

void turnLeft() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_A2, HIGH);
  digitalWrite(MOTOR_B1, HIGH);
  digitalWrite(MOTOR_B2, LOW);
}

void moveForward() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
  digitalWrite(MOTOR_A1, HIGH);//RIGH SIDE MOTOR
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B1, HIGH);//LEFT SIDE MOTOR
  digitalWrite(MOTOR_B2, LOW);
}
