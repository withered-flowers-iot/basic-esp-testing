#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX

void setup()
 {
   // Open serial communications and wait for port to open:
   Serial.begin(9600);
   mySerial.begin(9600);
 }
 
 void loop() // run over and over
 {
   while (mySerial.available()>0 )
     Serial.write(mySerial.read());
   while (Serial.available()>0 ){
      mySerial.write(Serial.read());
      delay(100);
    }
 }
/*
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop(){
  //while (Serial.available()>0 ){
    String response="";
    Serial.print("\nSerial Monitor send: ");
    Serial.print("AT");
    mySerial.print("AT\r\n");
    while(mySerial.available())
     {   
        // The esp has data so display its output to the serial window 
        char c = mySerial.read()-48; // read the next character.
        response+=c;
     }     
     Serial.print("\nESP 8266 response: ");
     Serial.print(response);
    delay(1000);
  //}
}  
/*
 // run over and over
void loop(){
 while (mySerial.available()>0)
   Serial.write(mySerial.read());
 while (Serial.available()>0 ){
    mySerial.write(Serial.read());
    delay(100);
  }
}*/
