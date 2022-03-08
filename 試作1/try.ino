#include <Stepper.h>

#define STEPS  32
#define PIN_1 9
#define PIN_2 10
#define PIN_3 11
#define PIN_4 12

#define RIGHT 3
#define LEFT 4
#define PR 5
#define ER 6
#define PL 7
#define EL 8
#define refDelayTime 3

#define DIN_PIN 13

int  Steps2Take;
int stepCounter = 0;
bool dropped = true;

Stepper small_stepper(STEPS, PIN_1, PIN_3, PIN_2, PIN_4);
  
void setup() {
  Serial.begin(9600);
  
  pinMode(RIGHT,INPUT);
  pinMode(LEFT,INPUT);
  pinMode(PR,OUTPUT);
  pinMode(ER,OUTPUT);
  pinMode(PL,OUTPUT);
  pinMode(EL,OUTPUT);
  pinMode(DIN_PIN, INPUT_PULLUP);
  
}

void loop() {

  if dropped = true{
      if ((digitalRead(RIGHT) == HIGH)&&(digitalRead(LEFT) == HIGH)) {
    
      digitalWrite(PR,HIGH);
      analogWrite(ER,200);
      digitalWrite(PL,HIGH);
      analogWrite(EL,200);
      
    } else if ((digitalRead(RIGHT) == LOW)&&(digitalRead(LEFT) == HIGH)){
      
      digitalWrite(PR,HIGH);
      analogWrite(ER,200);
      digitalWrite(PL,HIGH);
      analogWrite(EL,0);
      
    } else if ((digitalRead(RIGHT) == HIGH)&&(digitalRead(LEFT) == LOW)){
      
      digitalWrite(PR,HIGH);
      analogWrite(ER,0);
      digitalWrite(PL,HIGH);
      analogWrite(EL,200);
      
    } else {
      
      digitalWrite(PR,LOW);
      analogWrite(ER,0);
      digitalWrite(PL,LOW);
      analogWrite(EL,0);
      
    }

    stepCounter += refDelayTime;

  }
    

  
  if(stepCounter == 3000){

    dropped=false;

    digitalWrite(PR,HIGH);
    digitalWrite(ER,HIGH);
    digitalWrite(PL,HIGH);
    digitalWrite(EL,HIGH);
    
    small_stepper.setSpeed(1000);
    Steps2Take  =  2048;
    small_stepper.step(Steps2Take / 4);

    for (int i=0;i<1000;i++){
      if (digitalRead(DIN_PIN)==0){
        dropped=true
        stepCounter = 0;
        break;
      }
      delay(1);
    }
  }

  digitalWrite(PIN_1, LOW);
  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, LOW);
  digitalWrite(PIN_4, LOW);
      
  delay(refDelayTime);
  
}
















