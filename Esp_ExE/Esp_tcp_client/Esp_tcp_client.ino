
#include <ESP8266WiFi.h>
const char* ssid     = "Cinaple Wirless";     
const char* password = "password@cinaple";      
const char* host = "192.168.1.113"; 
const int   port = 8090;            
const int   watchdog = 50;        
unsigned long previousMillis = millis(); 
String mode="",id=""; 
  unsigned long timeout=0;
void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  unsigned long currentMillis = millis();
 
 // if ( currentMillis - previousMillis > watchdog ) {
 //   previousMillis = currentMillis;
  
    WiFiClient client;
  
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }

  if (Serial.available() >0) 
  {

    if (Serial.find("MODE="))
    {
       mode=Serial.readStringUntil('@');
      }
      
      if (Serial.find("ID="))
      {
          id=Serial.readStringUntil('*');
      }
      
    
  }
  else
  {
    mode="";
    id="";
    }

if(mode != ""&& id!="")
{
    Serial.print ("recived~~~");
    Serial.print (mode);
    Serial.print ("\t\t\t");
    Serial.println (id);
    String url = "/RFID_login?mode=";
    url += mode;
    url += "&id=";
    url += id;
    
 
    client.print(String("GET ") + url );
    mode="";
    id="";
}    
   /* 
    while (client.available() == 0) 
    {
      if (millis() - timeout > 5000) 
      {
        Serial.println(">>> Client Timeout !");
        client.stop();
        unsigned long timeout = millis();
        return;
      }
    }
  
  /*********************************************************************
    while(client.available())
    {
      String line = client.readStringUntil('\r');
     // Serial.print(line);
    }*/
 // }
}
