#include "Timer.h"
#include "RickSoundFiles.h"

int timeCount = 0;
int timeCount2 = 0;
unsigned int count = 0;
bool correctAnswer = false;   //to detect/convey button presses/value changed
int button = 3;
int X = A4;
int Y = A5;
int buzzer = 2;
int solution[4] = {4, 3, 2, 1};
int digitValues[4] = {0, 0, 0, 0};  //0 -> 3    4 digits
int currDigit = 0;
int beatSpeed = 114;
unsigned long previousmill;
int notesNumber = 76;
int wholenote = 240000/beatSpeed;
int soundLength = 0;

char gSegPins[] = {10, 12, 8, 7, 6, 11, 9};    //a b c d e f g   

enum XDIGIT {START, HOLD1, HOLD2, LEFT, RIGHT} dState = START;
void cursorSwitch(void)   {  //switch between the 4 digits
  switch (dState)    {
      case START:
          if (X > 900)  {dState = HOLD1;}
          else if (X < 60)  {dState = HOLD2;}
          else {dState = START;}
      break;

      case HOLD1:
          if (X < 520 && X > 490)   {dState = LEFT;}
          else {dState = HOLD1;}
      break;

      case LEFT:
          dState = START;
      break;

      case HOLD2:
          if (X < 520 && X > 490)   {dState = RIGHT;}
          else {dState = HOLD2;}
      break;
      
      case RIGHT:
      dState = START;
      break;
      
    default:
      START;
    break;
    }

    switch (dState)    {
      case START:
      break;

      case HOLD1:
      break;

      case LEFT:
          currDigit--;
          if (currDigit < 0)   {currDigit = 3;}
      break;

      case HOLD2:
      break;
      
      case RIGHT:
          currDigit++;
          if (currDigit > 3)   {currDigit = 0;}
      break;
      
      default:
      break;
    }
}

enum YDIGIT {WAIT, WAITRELEASE1, WAITRELEASE2, INCREASE, DECREASE} cState = WAIT;
void changeDigitalVals()   {   //use function to increment/de-increment count values
  switch (cState)    {//trsnaitions
      case WAIT:
          if (Y > 1000)  {cState = WAITRELEASE1;}
          else if (Y < 100)  {cState = WAITRELEASE2;}
          else {cState = WAIT;}
      break;

      case WAITRELEASE1:
          if (Y < 530 && Y > 480)   {cState = INCREASE;}
          else {cState = WAITRELEASE1;}
      break;

      case INCREASE:
          cState = WAIT;
      break;

      case WAITRELEASE2:
          if (Y < 530 && Y > 480)   {cState = DECREASE;}
          else {cState = WAITRELEASE2;}
      break;
      
      case DECREASE:
      cState = WAIT;
      break;
      
    default:
      WAIT;
    break;
    }

    switch (cState)    {//actions
      case WAIT:
      break;

      case WAITRELEASE1:
      break;

      case DECREASE:
          digitValues[currDigit]++;
          if (digitValues[currDigit] > 9)   {digitValues[currDigit] = 0;}
      break;

      case WAITRELEASE2:
      break;
      
      case INCREASE:
          if (digitValues[currDigit] <= 0)   {digitValues[currDigit] = 9;}
          else {digitValues[currDigit]--;}
      break;
      
      default:
      break;
    }
}


enum SWITCH_DIGITS {DIGIT1, DIGIT2, DIGIT3, DIGIT4} bState = DIGIT1;
void digitSwitch(void)   {
  switch (bState)   {  //transitions
    case DIGIT1:
        bState = DIGIT2;
    break;
    
    case DIGIT2:
        bState = DIGIT3;
    break;

    case DIGIT3:
        bState = DIGIT4;
    break;

    case DIGIT4:
        bState = DIGIT1;
    break;
  
    default: 
        DIGIT1;
    break;
 }  
 
  switch (bState)   {    //actions
    case DIGIT1:
         timeCount = 0;
         while (timeCount < 10)  {
              digitalWrite(A3, HIGH);
              count = digitValues[0];
              displayNumTo7Seg(count, A0);
              digitalWrite(A0, LOW);
              timeCount++; }
     break;
  
     case DIGIT2:
        timeCount = 0;
        while (timeCount < 10)  {
            digitalWrite(A0, HIGH);
            count = digitValues[1];
            displayNumTo7Seg(count, A1);
            digitalWrite(A1, LOW);
            timeCount++;}
     break;

     case DIGIT3:
        timeCount = 0;
        while (timeCount < 10)  {
            digitalWrite(A1, HIGH);
            count = digitValues[2];
            displayNumTo7Seg(count, A2);
            digitalWrite(A2, LOW);
            timeCount++;}
     break;
     
     case DIGIT4:
        timeCount = 0;
        while (timeCount < 10)  {
            digitalWrite(A2, HIGH);
            count = digitValues[3];
            displayNumTo7Seg(count, A3);
            digitalWrite(A3, LOW);
            timeCount++;}
     break;

     default: 
     break;
     }  
}

enum CHECK_INPUT {BUTTON_WAIT, RELEASE_WAIT, CHECK} rState = BUTTON_WAIT;
void playerCodeCheck(void)   {
  switch(rState)   {  //transitions
    case BUTTON_WAIT:
        if (button == 0)  {rState = RELEASE_WAIT;}
        else {rState = BUTTON_WAIT;}
    break;

    case RELEASE_WAIT:
        if (button == 0)  {rState = RELEASE_WAIT;}
        else {rState = CHECK;}
    break;

    case CHECK:
        rState = BUTTON_WAIT;
    break;

    default:
        BUTTON_WAIT;
    break;
    }
  switch(rState)   {  //actions
    case BUTTON_WAIT:
    break;

    case RELEASE_WAIT:
    break;

    case CHECK:
        correctAnswer = checkAnswer();
        if (correctAnswer) { 
            for (int n = 0; n < notesNumber; n++) {
                if (duration[n] < 0) {
                  soundLength = wholenote/(duration[n]*-1);
                  soundLength = soundLength+(soundLength*0.5);
                }
                else if (duration[n] > 0) {
                  soundLength = (wholenote)/duration[n];;
                } 
                previousmill = millis();
                tone(buzzer, melody[n], soundLength*0.9);
                while(((millis() - previousmill) / soundLength) < 1){}
                    digitSwitch();      //makes sure display is lit as for loop is executed
                    noTone(buzzer);
            }
            solutionRandomizer();
            Serial.println(solution[0]);
            Serial.println(solution[1]);
            Serial.println(solution[2]);
            Serial.println(solution[3]);
        }           
        else {
          inputResponseSound();
          }
    break;

    default:
    break;
    }
  }

void inputResponseSound(void)   {
  for (int j = 3; j > -1; j--)   {
          if (digitValues[j] == solution[j])   {
            while (timeCount2 < 250)  {
              digitSwitch();      //makes sure display is lit as for loop is executed
              tone(buzzer, 750);
              timeCount2++;
            }
          }
          else {
            while (timeCount2 < 250)  {
              digitSwitch();      //makes sure display is lit as for loop is executed
              tone(buzzer, 350);
              timeCount2++;
            }
          }
          timeCount2 = 0;
          while (timeCount2 < 250)  {
            digitSwitch();      //makes sure display is lit as for loop is executed
              noTone(buzzer);
              timeCount2++;
          }
          timeCount2 = 0;
  }
}

bool checkAnswer(void)   {
  int validValue = 0;
        for (int i = 0; i < 4; i++)   {
          if (digitValues[i] == solution[i])   {validValue++;}
          }
        if (validValue >= 4)   {
          return true;}
        return false;
  }

void solutionRandomizer(void)    {
    int randomValue;
    for (int k = 0; k < 4; k++)   {
      randomValue = random(0, 9);
      solution[k] = randomValue; 
      }
}
 
void displayNumTo7Seg(unsigned int targetNum, int digitPin) {  //function provided by TA in googledrive files
    unsigned char encodeInt[10] = {
        // 0     1     2     3     4     5     6     7     8     9
        0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67,
    };
    digitalWrite(digitPin, HIGH);
    // Update the segments
    for (int k = 0; k < 7; ++k) {
        digitalWrite(gSegPins[k], encodeInt[targetNum] & (1 << k));
    }
    // Turn on the digit again
    digitalWrite(digitPin, LOW);
}
 
 void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);  //D1
  pinMode(A1, OUTPUT);  //D2
  pinMode(A2, OUTPUT);  //D3
  pinMode(A3, OUTPUT);  //D4
  pinMode(button, INPUT_PULLUP);
  pinMode(A4, INPUT);  //D1
  pinMode(A5, INPUT);    //10, 12, 8, 7, 6, 11, 9
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(button, HIGH);
  solutionRandomizer();
  
  TimerSet(1);
  TimerOn();
}

void loop() {
  X = analogRead(A4);
  Y = analogRead(A5);
  button = digitalRead(3);
  cursorSwitch();
  changeDigitalVals();
  digitSwitch();
  playerCodeCheck();
  while(!TimerFlag)   {}
    TimerFlag=0;
  }
