
/* Transmitter Code
   Code to read Joystick position and transmit it with a RF24L01+ to a receiver
*/

#include <SPI.h>
#include <RF24.h>

// Radio Configuration

RF24 radio(9, 10);
byte addresses[][6] = {"1Node", "2Node"};
bool radioNumber = 1;
bool role = 1;  //Control transmit 1/receive 0

// Decide where you are going to plug the joystick into the circuit board.

int ForeAft_Pin = A6;        // Plug Joystick Fore/Aft into Analog pin 0
int LeftRight_Pin = A7;      // Plug Joystick Left/Right into Analog pin 1

// Create variables to read joystick values
int input[2];


// Create variables to transmit servo value

int ForeAft_Output;       // Expected range 0 - 180 degrees
int LeftRight_Output;     // Expected range 0 - 180 degrees

void setup() {
  Serial.begin(9600);                   // Get ready to send data back for debugging purposes
  radio.begin();                        // Get the transmitter ready
   radio.setChannel(108);  // 2.508 Ghz - Above most Wifi Channels
  radio.setDataRate(RF24_250KBPS); // Fast enough.. Better range

  // Set the Power Amplifier Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  // PALevelcan be one of four levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setPALevel(RF24_PA_LOW);
  //   radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(addresses[1]);  // Where we send data out
  //radio.openReadingPipe(role, addresses[0]); // Where we receive data back
  radio.stopListening();
}
void loop() {
  input[0] = analogRead(ForeAft_Pin);
  input[1] =analogRead(LeftRight_Pin);   // Read the Left/Right joystick value
  
                 
radio.write(&input, sizeof(input));   
delay(5);//Send ForeAft data
 
 // radio.startListening();
    Serial.print("x == ");
     Serial.print(analogRead(ForeAft_Pin));
     Serial.print("  ~~~~~~~~~~~~~~ y== ");
     Serial.println(analogRead(LeftRight_Pin));// Get ready to receive confirmation from receiver
}



