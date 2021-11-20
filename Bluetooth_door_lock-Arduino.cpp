#include <Servo.h>

Servo myservo;  

String inputString = "";
String command = "";
String value = "";
String password = "Sahitya"; 
boolean stringComplete = false; 

void setup(){
  Serial.begin(9600);  
  inputString.reserve(50); 
  command.reserve(50);
  value.reserve(50);
  
  boolean stringOK = false;
  
  myservo.attach(9); 
  
}

void loop(){
 
  if (stringComplete) {
    delay(100);
    int pos = inputString.indexOf('=');
   
    if (pos > -1) {
        command = inputString.substring(0, pos);
        value = inputString.substring(pos+1, inputString.length()-1);
        
    if(!password.compareTo(value) && (command == "OPEN")){
           openDoor(); 
           Serial.println(" OPEN"); 
           delay(100);
           }
    else if(!password.compareTo(value) && (command == "CLOSE")){
           closeDoor();
           Serial.println(" CLOSE");  
           delay(100);
           }
    else if(password.compareTo(value)){
           Serial.println(" WRONG");
           delay(100);
           } 
        } 
       inputString = "";
       stringComplete = false;
    }
   
}


void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read(); 
    inputString += inChar;
    if (inChar == '\n' || inChar == '\r') {
      stringComplete = true;
    } 
  }
}

void openDoor(){
  myservo.write(0); 
  delay(100);   
}

void closeDoor(){
  myservo.write(65);
  delay(100); 
}