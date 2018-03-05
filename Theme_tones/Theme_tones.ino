
#include "pitches.h" //add Equivalent frequency for musical note
#include "themes.h" //add Note vale and duration 
 #include <stdio.h>

void Play_Pirates()
{ 
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Pirates_duration[thisNote];//convert duration to time delay
    tone(11, Pirates_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.05; //Here 1.05 is tempo, increase to play it slower
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}

void Play_CrazyFrog()
{
  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(11, CrazyFrog_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}

void Play_MarioUW()
{
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(11, MarioUW_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}

void Play_Titanic()
{
    for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Titanic_duration[thisNote];//convert duration to time delay
    tone(11, Titanic_note[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 2.70;
    delay(pauseBetweenNotes);
    noTone(8); //stop music on pin 8 
    }
}

void setup() {

Serial.begin(9600);

Serial.println("Replay with :\n1. Play_Pirates \n2. Play_CrazyFrog \n3. Play_MarioUW\n4. Play_Titanic ");
}

void loop() {

  
while (Serial.available() > 0) {

 int x=Serial.parseInt();
 // Serial.println(x);
    if (Serial.find('\n')) {
    
  
  
    if (x==1)
      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Pirates();  }
    if (x==2)
      { Serial.println("Selected -> 'Crazy Frog' ");  Play_CrazyFrog();  }
    if (x==3)
      { Serial.println("Selected -> 'Mario UnderWorld' ");  Play_MarioUW();  }
    if (x==4)
      { Serial.println("Selected -> 'Titanic' ");  Play_Titanic();  }
   }
}
}
