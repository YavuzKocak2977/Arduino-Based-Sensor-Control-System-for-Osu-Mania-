#include <Servo.h>

const int LED1 =2;  // I'm using pwm signal right here to see temperature with 5 more led.
const int LED2 =3;  // When the temperature is low led light less however when the temp is high enough
const short int LED3 =4;  // another led lights on and shine more.
const short int LED4 =5;
const short int LED5 =6;

const short int LED6 =31;
const short int LED7 =32;
const short int LED8 =33;  // Those LED are for the fallow up for the people.
const short int LED9 =34;

const short int Servo1 =7;  // Tose servo is used for touch
const short int Servo2 =8;
const short int Servo3 =9;
const short int Servo4 =10;

const short int Tus1 =14;  // Those sensor are emulate keyboeard
const short int Tus2 =15;
const short int Tus3 =16;
const short int Tus4 =17;

const short int LDR1 =A0;  // LDR is used for read notes
const short int LDR2 =A1;
const short int LDR3 =A2;
const short int LDR4 =A3;

const short int Sicaklik_sensoru=A5;
float sicaklik_C;
float isik_kontrol;

Servo servo_motor_1;
Servo servo_motor_2;
Servo servo_motor_3;
Servo servo_motor_4;

void setup() {

  Serial.begin(9600);

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);  // LED needs output signal
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);

  pinMode(LED6,OUTPUT);
  pinMode(LED7,OUTPUT);
  pinMode(LED8,OUTPUT);
  pinMode(LED9,OUTPUT);

  servo_motor_1.attach(Servo1);
  servo_motor_2.attach(Servo2);
  servo_motor_3.attach(Servo3);
  servo_motor_4.attach(Servo4);

  pinMode(Tus1,INPUT_PULLUP);
  pinMode(Tus2,INPUT_PULLUP);
  pinMode(Tus3,INPUT_PULLUP);
  pinMode(Tus4,INPUT_PULLUP);
  
  pinMode(LDR1,INPUT);
  pinMode(LDR2,INPUT);
  pinMode(LDR3,INPUT);
  pinMode(LDR4,INPUT);

  pinMode(Sicaklik_sensoru,INPUT);
}

void loop() {

  int LDR1_deger = analogRead(LDR1);
  int LDR2_deger = analogRead(LDR2);
  int LDR3_deger = analogRead(LDR3);
  int LDR4_deger = analogRead(LDR4);


if (LDR1_deger < 400){
  servo_motor_1.write(60);  // in there servo 1 push the touch sensor cause light came, therefore servo goes 60 degree
} else {
  servo_motor_1.write(90);  // in there servo 1 release the touch sensor cause light out, therefore servo goes 90 degree
}

if (LDR2_deger < 400){
  servo_motor_2.write(60);
} else {
  servo_motor_2.write(90);
}

if (LDR3_deger < 400){
  servo_motor_3.write(60);
} else {
  servo_motor_3.write(90);
}

if (LDR4_deger < 400){
  servo_motor_4.write(60);
} else {
  servo_motor_4.write(90);
}

  int Sicaklik_sensoru_deger = analogRead(Sicaklik_sensoru);
  sicaklik_C = (Sicaklik_sensoru_deger / 1023.0) * 500.0;

  if (sicaklik_C >=40 && sicaklik_C<=50){

    isik_kontrol= 255-((50 - sicaklik_C)/10)*255;

    if (isik_kontrol<0){
      isik_kontrol=0;
    } else if (isik_kontrol > 255){
      isik_kontrol=255;
    }

    analogWrite(LED1,255);
    analogWrite(LED2,255);
    analogWrite(LED3,255);
    analogWrite(LED4,255);
    analogWrite(LED5,isik_kontrol);

  } else if  (sicaklik_C >=30 && sicaklik_C<40){

    isik_kontrol= 255-((40 - sicaklik_C)/10)*255;
    if (isik_kontrol<0){
      isik_kontrol=0;
    } else if (isik_kontrol > 255){
      isik_kontrol=255;
    }
    
    analogWrite(LED1, 255);
    analogWrite(LED2, 255);
    analogWrite(LED3, 255);
    analogWrite(LED4, isik_kontrol);
    analogWrite(LED5, 0);

  } else if (sicaklik_C >=20 && sicaklik_C<30){
    
    isik_kontrol= 255-((30 - sicaklik_C)/10)*255;
    if (isik_kontrol<0){
      isik_kontrol=0;
    } else if (isik_kontrol > 255){
      isik_kontrol=255;
    }
    
    
    analogWrite(LED1, 255);
    analogWrite(LED2, 255);
    analogWrite(LED3, isik_kontrol);
    analogWrite(LED4, 0);
    analogWrite(LED5, 0);

  } else if (sicaklik_C >=10 && sicaklik_C<20) {

    isik_kontrol= 255-((20 - sicaklik_C)/10)*255;

    if (isik_kontrol<0){
      isik_kontrol=0;
    } else if (isik_kontrol > 255){
      isik_kontrol=255;
    }

    analogWrite(LED1, 255);
    analogWrite(LED2, isik_kontrol);
    analogWrite(LED3, 0);
    analogWrite(LED4, 0);
    analogWrite(LED5, 0);

  } else if (sicaklik_C >=0 && sicaklik_C<10){

    isik_kontrol= 255-((10 - sicaklik_C)/10)*255;

    if (isik_kontrol<0){
      isik_kontrol=0;
    } else if (isik_kontrol > 255){
      isik_kontrol=255;
    }

      analogWrite(LED1, isik_kontrol);
      analogWrite(LED2, 0);
      analogWrite(LED3, 0);
      analogWrite(LED4, 0);
      analogWrite(LED5, 0);

  }
  
  static bool kontrol_1=false;
  static bool kontrol_2=false;
  static bool kontrol_3=false;
  static bool kontrol_4=false;

  bool Tus1_deger = digitalRead(Tus1);

  if (Tus1_deger == LOW){

    if(kontrol_1==false){

      kontrol_1=true;
      Serial.print("dD");
      digitalWrite(LED6, HIGH);

    }

    delay(1);

  } else {

    if (kontrol_1 == true){

      Serial.print("dU");
      kontrol_1 = false;
      digitalWrite(LED6, LOW);

    }

    delay(1);

  }

  bool Tus2_deger = digitalRead(Tus2);

    if (Tus2_deger == LOW){

      if(kontrol_2==false){

        kontrol_2=true;
        Serial.print("fD");
        digitalWrite(LED7, HIGH);

    }

    delay(1);

  } else {

    if (kontrol_2 == true){

      Serial.print("fU");
      kontrol_2 = false;
      digitalWrite(LED7, LOW);

    }

    delay(1);

  }

  bool Tus3_deger = digitalRead(Tus3);

    if (Tus3_deger == LOW){

      if(kontrol_3==false){
        kontrol_3=true;
        Serial.print("jD");
        digitalWrite(LED8, HIGH);

    }

    delay(1);

  } else {

    if (kontrol_3 == true){

      Serial.print("jU");
      kontrol_3 = false;
      digitalWrite(LED8, LOW);

    }

    delay(1);

  }

  bool Tus4_deger = digitalRead(Tus4);

    if (Tus4_deger == LOW){
      
      if(kontrol_4==false){

        kontrol_4=true;
        Serial.print("kD");
        digitalWrite(LED9, HIGH);

    }

    delay(1);

  } else {

    if (kontrol_4 == true){

      Serial.print("kU");
      kontrol_4 = false;
      digitalWrite(LED9, LOW);

    }

    delay(1);

  }
  
}
