#define POT A0

int cont;
int cont2;
String Datos;
int buttonled=12;
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
     // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int LeePot;
//SoftwareSerial mySerial(8, 9);


void setup() {
  
  // initialize the LED pin as an output:
 // digitalWrite(buttonled,OUTPUT);
  // initialize the pushbutton pin as an input:
//  mySerial.begin(115200);
Serial2.begin(115200);
 pinMode(8, INPUT);
 pinMode(9, OUTPUT); 
  pinMode(buttonPin, INPUT);
  pinMode(buttonled, OUTPUT);
  Serial.begin(115200);
  pinMode(POT,INPUT);
  cont2 =1;
}

void loop() {
 
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  LeePot = analogRead(POT);
  Serial.println(LeePot);
  
  if(buttonState==0){
    cont = cont +1;
    }

  //String conc = LeePot;
  
  char v1[] = "test"; 
  
 // mySerial.println(buttonState);
 
   Serial2.print(String('b')+String(buttonState)+String('p')+String(LeePot)+String('c')+String(cont)+String('\n'));
    
    
 /*   if(mySerial.available()){
    Datos = mySerial.readStringUntil('\n');
    Serial.println("hola"+Datos);
  }else{
    Serial.println("Sin datos");
    }*/
        if(Serial2.available()){
    Datos = Serial2.readStringUntil('\n');
    Serial.print(Datos);
    
  if(Datos.toInt() == 1){
      digitalWrite(buttonled,LOW);
      Serial.println("encendido");
    }else{
       digitalWrite(buttonled,HIGH);
       Serial.println("apagado");
       }
    }else{
    Serial.println("Sin datos");
    }


delay(100);

  
}
