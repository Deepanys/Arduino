/**
 * Two Channel Receiver
 * Author: Shawn Hymel (SparkFun Electronics)
 * Date: Aug 24, 2017
 * 
 * Connect a TB6612FNG and RC (PWM) receiver to the Arduino.
 * Mixes two channels for arcade drive.
 * 
 * This code is beerware; if you see me (or any other SparkFun 
 * employee) at the local, and you've found our code helpful, 
 * please buy us a round! 
 * Distributed as-is; no warranty is given.
 */

// Controller pins
const int CH_1_PIN = 9;

const int deadzone = 10;
// Motor driver pins

// Parameters
  // Anything between -20 and 20 is stop

void setup() {
Serial.begin(115200);
  
}

void loop() {

  // Read pulse width from receiver
 
  int x = pulseIn(CH_1_PIN, HIGH, 25000);//9
    

  // Convert to PWM value (-255 to 255)
 
  x = pulseToPWM(x);
Serial.print("ch 1 == ");
  Serial.println(x);//10
  

  // Mix for arcade drive
 // int left = y + x;
 // int right = y - x;

  // Drive motor
 // drive(left, right);

  delay(5);
}

/*/ Positive for forward, negative for reverse
void drive(int speed_a, int speed_b) {

  // Limit speed between -255 and 255
  speed_a = constrain(speed_a, -255, 255);
  speed_b = constrain(speed_b, -255, 255);

  // Set direction for motor A
  if ( speed_a == 0 ) {
    digitalWrite(AIN1_PIN, LOW);
    digitalWrite(AIN2_PIN, LOW);
  } else if ( speed_a > 0 ) {
    digitalWrite(AIN1_PIN, HIGH);
    digitalWrite(AIN2_PIN, LOW);
  } else {
    digitalWrite(AIN1_PIN, LOW);
    digitalWrite(AIN2_PIN, HIGH);
  }

  // Set direction for motor B
  if ( speed_b == 0 ) {
    digitalWrite(BIN1_PIN, LOW);
    digitalWrite(BIN2_PIN, LOW);
  } else if ( speed_b > 0 ) {
    digitalWrite(BIN1_PIN, HIGH);
    digitalWrite(BIN2_PIN, LOW);
  } else {
    digitalWrite(BIN1_PIN, LOW);
    digitalWrite(BIN2_PIN, HIGH);
  }

  // Set speed
  analogWrite(APWM_PIN, abs(speed_a));
  analogWrite(BPWM_PIN, abs(speed_b));
}

/*/// Convert RC pulse value to motor PWM value
int pulseToPWM(int pulse) {
  
  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 3 ) {
    pulse = constrain(pulse, 6, 1932);
    pulse = map(pulse, 6, 1932, -255, 255);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }

  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
   pulse = 0;
   }
///
  return pulse;
}
