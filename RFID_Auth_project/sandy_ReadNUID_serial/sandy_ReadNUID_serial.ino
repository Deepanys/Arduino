/*

 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define SS_PIN 10
#define RST_PIN 9

Servo door; 

 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];

String entry,mode="open",card,ack;
String(match)="0716624841";
LiquidCrystal_I2C display(0b00111111, 16, 2);
void setup() { 

  Serial.begin(9600);
  SPI.begin(); 
  
  rfid.PCD_Init(); 
  
  display.begin();
  display.backlight();
  display.print("Initializing.......");
  
  door.attach(3);
 door.write(160); 
  delay(1000);

 // Serial.println(F("This code scan the MIFARE Classsic NUID."));
  
}
 
void loop() {

  // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

 

  // Check is the PICC of Classic MIFARE type


 /* if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {*/
   // Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }

   // for (byte i = 0; i < 4; i++) {
    //  Serial.println (nuidPICC[i]) ;
    //}
 
   /*7
166
248
41
*/
   
  
  if (nuidPICC[0]==7|| 
     nuidPICC[1]== 166|| 
    nuidPICC[2]== 248|| 
     nuidPICC[3]==41 )
     {
      Serial.print("Match ");
      if( mode =="open")
            {
             Serial.print("MODE=");
             Serial.print(mode);
             Serial.println("@");
             Serial.print("ID=");
             for (byte i = 0; i < 4; i++)   
             {
                 Serial.print (nuidPICC[i]) ;
              }
             Serial.println("*"); 
              display.clear();
              display.setCursor(0,0);
              display.print("Access Granted.....!");
              display.setCursor(0,1);
              display.print("...Opeaning...");
          
                   for (int pos = 10; pos <= 160; pos += 1)
                  { 
                    door.write(pos);             
                    delay(5);                    
                  }
                
                mode ="close";
            }
          
            else
            if( mode =="close")
            {
             Serial.print("MODE=");
             Serial.print(mode);
             Serial.println("@");
             Serial.print("ID=");
              for (byte i = 0; i < 4; i++)   
             {
                 Serial.print (nuidPICC[i]) ;
              }
             Serial.println("*");
              display.clear();
              display.setCursor(0,0);
              display.print("Access Granted.....");
              display.setCursor(0,1);
              display.print("...Closing...");
                  for (int pos = 160; pos >= 10; pos -= 1) 
                  { 
                    door.write(pos);              
                    delay(5);                       
                  }
              mode ="open";
          
          }
      }

      else
      {
        
             Serial.print("MODE=");
             Serial.print("Breach");
             Serial.println("@");
              Serial.print("ID=");
             for (byte i = 0; i < 4; i++)   
             {
                 Serial.print (nuidPICC[i]) ;
              }
             Serial.println("*"); 
              display.clear();
              display.setCursor(0,0);
              display.print("Access Denied..!");
              display.setCursor(0,1);
              display.print("!!!Wrong Entry!!!");
        
        }
  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  Serial.println("\n##### Please Register your ID #####");
}



