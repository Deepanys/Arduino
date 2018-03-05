/*  Receiver Code 
*   Code to receive data from RF24L01+ and use it to control a servo */

#include <SPI.h>
#include <RF24.h>



//Radio Configuration

bool radioNumber=0;
RF24 radio(9,10);
byte addresses[][6] = {"1Node","2Node"};
bool role = 0;  //Control transmit/receive

// Create variables to control servo value


int ForeAft_Output[1];       // Expected range 0 - 180 degrees
 unsigned int LeftRight_Output;     // Expected range 0 - 180 degrees

void setup() { 


  
    Serial.begin(9600);        // Get ready to send data back for debugging purposes
    radio.begin();             // Initialize radio
    radio.setPALevel(RF24_PA_LOW);    // Set the power output to low
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(role,addresses[1]);
    radio.startListening();
}
void loop() {
    delay(500);               //increase for debuggy, decrease to decrease jitter
    if(radio.available()){
        radio.read(&ForeAft_Output,sizeof(ForeAft_Output));
       // radio.read(&LeftRight_Output,sizeof(LeftRight_Output));
        } else {Serial.print("No radio");
    }
    Serial.println(ForeAft_Output[0]);
   Serial.print("\t");
   Serial.println(ForeAft_Output[1]);
/******************************************************/


   
    }



