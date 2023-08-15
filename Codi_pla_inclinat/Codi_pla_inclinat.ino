#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define SensorSalida 8

#include <Servo.h>
Servo myservo;
int Pin_servo= 9;

int Comenca=0;

int Pin_boto=2;

int Segons=0;
int Minuts=0;
int Hores=0;

int Rojo_Freq=0;
int Verde_Freq=0;
int Azul_Freq=0;

int Obertura=0;

void setup() {
  pinMode(Pin_boto, INPUT);
  pinMode (S0, OUTPUT);
  pinMode (S1, OUTPUT);
  pinMode (S2, OUTPUT);
  pinMode (S3, OUTPUT);
  pinMode (SensorSalida, INPUT);
  myservo.attach(Pin_servo);
  digitalWrite(S0, LOW);
  digitalWrite(S1,HIGH);
  Serial.begin (9600);
  myservo.write (0);
}

void loop(){
  int Boto_lectura=digitalRead(Pin_boto);
  if (Boto_lectura == 0) {
    Comenca+=1;}
    
  if (Comenca > 0) {    
    
    if (Obertura == 0){
      myservo.write (40);
      delay(200);
      myservo.write (0);
      Obertura+=1;
    } 
    temps();
  }}
  
void temps () {
  digitalWrite (S2, LOW);
  digitalWrite (S3, LOW);
  Rojo_Freq=pulseIn(SensorSalida,LOW);
    

  digitalWrite (S2, HIGH);
  digitalWrite (S3, HIGH);
  Verde_Freq=pulseIn(SensorSalida,LOW);


  digitalWrite (S2, LOW);
  digitalWrite (S3, HIGH);
  Azul_Freq=pulseIn(SensorSalida,LOW);

  Serial.print(Rojo_Freq);
  Serial.print(",");
  Serial.print(Verde_Freq);
  Serial.print(",");
  Serial.println(Azul_Freq);

  if (16 <= Rojo_Freq && Rojo_Freq <= 80 && 18 <= Verde_Freq && Verde_Freq < 90 && 18 <= Azul_Freq && Azul_Freq < 70) {
    myservo.write (40);
    delay (320);
    myservo.write(0);
    delay (200);
    Segons+=0.88;}

  if (Segons >= 60){
    Minuts+=1;
    Segons-=60;}
  if (Minuts == 60){
    Hores+=1;
    Minuts-=60;}
}
