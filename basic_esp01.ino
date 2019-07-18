#include <SoftwareSerial.h>
#define RX 2
#define TX 3
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
SoftwareSerial esp01(RX,TX); 
 
  
void setup() {
  Serial.begin(9600);
  esp01.begin(115200);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWJAP=\"BlockMatrix\",\"FIREBIRD333\"",20,"OK");
}
void loop() {
 

}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp01.println(command);//at+cipsend
    if(esp01.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OK");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
