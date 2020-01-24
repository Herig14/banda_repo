#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
SoftwareSerial nodo(D7,D8); 
int Led_OnBoard = 2;                  // Initialize the Led_OnBoard 
boolean m;
boolean p;
String datos;
String d1;

int b1,b2; 
const char* ssid = "PROYECTOBANDA";                  // Your wifi Name       
const char* password = "BandaProyecto";          // Your wifi Password

const char *host = "192.168.1.101"; //Your pc or server (database) IP, example : 192.168.0.0 , if you are a windows os user, open cmd, then type ipconfig then look at IPv4 Address.

void setup() {
  // put your setup code here, to run once:
  nodo.begin(115200);
  pinMode(D7,INPUT);
  pinMode(D8,OUTPUT);
  delay(1000);
  pinMode(Led_OnBoard, OUTPUT);       // Initialize the Led_OnBoard pin as an output
  Serial.begin(115200);
  
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(Led_OnBoard, LOW);
    delay(250);
    Serial.print(".");
    digitalWrite(Led_OnBoard, HIGH);
    delay(250);
  }

  digitalWrite(Led_OnBoard, HIGH);
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

void loop() {
  // put your main code here, to run repeatedly:
  if(nodo.available()){
  delay(50);
   datos = nodo.readStringUntil('\n');
   //Serial.println(datos);
   for(int i=0;i<datos.length();i++){
    datos.charAt(i);
    if(datos.charAt(i)=='d'){
       b1=i;
    }else if(datos.charAt(i)=='\n'){
      b2=i;
    }
   }
   
}else{
  delay(100);
  Serial.println("No entra nada xD");
}
   //d1=datos.substring(b1+1,b2+1);
   Serial.print(datos);
  HTTPClient http;    //Declare object of class HTTPClient
 
  String LdrValueSend, postData;
  // aqui va distance en double
 // String ldrvalue=datos;  //Read Analog value of LDR
  
  LdrValueSend = d1;   //String to interger conversion
 
  //Post Data
  postData = "ldrvalue=" + LdrValueSend;
  
  http.begin("http://192.168.1.101/banda/insertdb");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

  //Serial.println("LDR Value=" + ldrvalue);
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  Serial.println("LDR Value=" + LdrValueSend);
  
  http.end();  //Close connection

  delay(400);  //Here there is 4 seconds delay plus 1 second delay below, so Post Data at every 5 seconds
  digitalWrite(Led_OnBoard, LOW);
  delay(100);
  digitalWrite(Led_OnBoard, HIGH);
  datos = "";
}
