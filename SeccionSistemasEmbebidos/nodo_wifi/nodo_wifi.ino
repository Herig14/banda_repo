#include <SoftwareSerial.h>

String datos;
String d1;
String d2,d3;
int est;
int i,b1,b2,b3;     
SoftwareSerial nodo(D7,D8); //rx tx

void setup() {
  // put your setup code here, to run once:
nodo.begin(115200);
pinMode(D7,INPUT);
pinMode(D8,OUTPUT);
///////////////////////////////
Serial.begin(115200);
pinMode(pul, INPUT);

}

void loop() {
est=digitalRead(pul);
//Serial.println(est); 
nodo.println(est); //Mando el dato del Pulsador 
delay(5);


if(nodo.available()){
  delay(50);
   datos = nodo.readStringUntil('\n');
   //Serial.println(datos);
   for(i=0;i<datos.length();i++){
    datos.charAt(i);
    if(datos.charAt(i)=='b'){
       b1=i;
    }else if(datos.charAt(i)=='p'){
      b2=i;
    }else if(datos.charAt(i)=='c'){
      b3=i;
    }
   }
   d1=datos.substring(b1+1,b2);
   Serial.println("Boton: "+d1);
   d2=datos.substring(b2+1,b3);
   Serial.println("Potenciometro: "+d2);
   d3=datos.substring(b3+1,datos.length());
   Serial.println("Contador: "+d3);
   
}else{
  delay(100);
  //Serial.println("No entra nada xD");
}
}
