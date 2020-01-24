const int sensorPin = 2;
 int contador = 0;
void setup() {
  Serial.begin(9600);   //iniciar puerto serie
  pinMode(sensorPin, INPUT);  //definir pin como entrada
}
 
void loop(){

 
  if (digitalRead(sensorPin) == HIGH) {
     
           
  }else{
    contador++;
      Serial.println(contador);
  }
  delay(25);
}
