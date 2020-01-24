#include <Servo.h>
Servo myservo;  
int motor=7;
int pos = 0;
const int trigPin = 6;
const int echoPin = 5;
const int sensorPin = 2;
int contador = 0;
long duration;
double distance;
int rx=8;
int tx=9;
int rojo=22;
int verde=23;
int amarillo=24;
String DatosRecibidos;
void setup() {
myservo.attach(10);
pinMode(motor,OUTPUT);
pinMode(verde,OUTPUT);
pinMode(rojo,OUTPUT);
pinMode(amarillo,OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(sensorPin, INPUT);
digitalWrite(motor,LOW);//hay que sacarle de aqui
Serial.begin(115200);
Serial3.begin(115200);
//pinMode(rx,INPUT);
//pinMode(tx,OUTPUT);
}

void loop() {
  
  estadosWeb();
  if(digitalRead(motor)==1){
  ultrasonic();
  }
  
  //infra();
  delay(50);
}
void servo(){
   
   digitalWrite(amarillo,HIGH);
   pos = 180;
   myservo.write(pos);              
   delay(100);
   //servo 100% CCW (equivalente a angulo 0º)
   pos = 0;
   myservo.write(pos);
   digitalWrite(amarillo,LOW);
}
void ultrasonic(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
 // delay(50);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel timein microsecon
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  //Serial.println(distance);
  if(distance >= 13){
    distance = 0;
    }else{
      distance = 13 -distance;
      }
   if(distance>0.9){
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial3.print(String('d')+String(distance)+String('\n'));
    Serial.print(String('d')+String(distance)+String('\n'));
    
    if(distance>1 and distance< 2.7){
      }else{
        delay(450);
        servo();
        }
   }
  // delay(250);
  
}

void estadosWeb(){
  
  if(Serial3.available()){
    DatosRecibidos = Serial3.readStringUntil('\n');
    Serial.println(DatosRecibidos);
  // Serial.println(digitalRead(motor));

  if(DatosRecibidos == "B"){
        if(digitalRead(motor)==0){
      Serial.print("encedido");
       digitalWrite(motor,HIGH);
       digitalWrite(verde,HIGH);
       digitalWrite(rojo,LOW);
         
      }else if(digitalRead(motor)==1){
        digitalWrite(motor,LOW);
         digitalWrite(rojo,HIGH);
         digitalWrite(verde,LOW);
         
        }
     
      
    }else if(DatosRecibidos == "P"){
      
      servo();
      }
    }else if(DatosRecibidos == "f"){
  //  Serial.println("nada y tu");

    } 
}

void infra(){
   if (digitalRead(sensorPin) == HIGH) {           
  }else{
    contador++;
      //Serial.println(contador);
  }
  delay(25);
  
}
