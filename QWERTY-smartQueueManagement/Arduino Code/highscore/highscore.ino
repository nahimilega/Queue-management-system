#include "Time.h"
#include "TimeLib.h"

#include "LedControl.h"

LedControl lc=LedControl(12,11,10,4);  // Pins: DIN,CLK,CS, # of Display connected
 
unsigned long delayTime=1000;  // Delay between Frames
int playerScore = 0;


byte yourFirst[] = {

  B00000000,
  B10001001,
  B01010010,
  B00100010,
  B00100010,
  B00100001,
  B00000000,
  B00000000
};


byte yourSecond[] = {

  B00000000,
  B00101011,
  B10101010,
  B10101011,
  B10101011,
  B00111010,
  B00000000,
  B00000000
};



byte yourThird[] = {
   B00000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000
};









byte IMAGESfirst[][8] = {
  
{
  B00000000,
  B00000011,
  B00000010,
  B00000010,
  B00000010,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000001,
  B00000011,
  B00000001,
  B00000001,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000001,
  B00000010,
  B00000000,
  B00000001,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000000,
  B00000011,
  B00000000,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000010,
  B00000010,
  B00000011,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000010,
  B00000011,
  B00000000,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000010,
  B00000011,
  B00000010,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000000,
  B00000000,
  B00000001,
  B00000001,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000010,
  B00000011,
  B00000010,
  B00000011,
  B00000000,
  B00000000
},{
  B00000000,
  B00000011,
  B00000010,
  B00000011,
  B00000000,
  B00000011,
  B00000000,
  B00000000
}};



byte IMAGESsecond[][8] = {
  {
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B01000000,
  B10000000,
  B00000000,
  B11000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B11000000,
  B01000000,
  B10000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
},{
  B00000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B00000000,
  B00000000
}};

byte IMAGESlast[][8] = {
  {
  B00000000,
  B00011100,
  B00010100,
  B00010100,
  B00010100,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00001000,
  B00011000,
  B00001000,
  B00001000,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00001100,
  B00010010,
  B00000100,
  B00001000,
  B00011110,
  B00000000,
  B00000000
},{
  B00000000,
  B00011100,
  B00000100,
  B00011100,
  B00000100,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00010100,
  B00010100,
  B00011100,
  B00000100,
  B00000100,
  B00000000,
  B00000000
},{
  B00000000,
  B00011100,
  B00010000,
  B00011100,
  B00000100,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00011100,
  B00010000,
  B00011100,
  B00010100,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00011110,
  B00000010,
  B00000100,
  B00001000,
  B00001000,
  B00000000,
  B00000000
},{
  B00000000,
  B00011100,
  B00010100,
  B00011100,
  B00010100,
  B00011100,
  B00000000,
  B00000000
},{
  B00000000,
  B00011100,
  B00010100,
  B00011100,
  B00000100,
  B00011100,
  B00000000,
  B00000000
}};


byte firstBoard[] = {
   B00000000,  // 
   B10010111, 
   B10010001,
   B11110001,
   B10010001,
   B10010111,
   B00000000,
   B00000000
};

byte secondBoard[] = {
   B00000000,  
   B11011110,
   B00010000,
   B00010110,
   B00010010,
   B11011110,
   B00000000,
   B00000000
};

byte initialthirdBoard[] = {
   B00000000,   
   B10010000, 
   B10010000,
   B11110000,
   B10010000,
   B10010000,
   B00000000,
   B00000000
};
byte thirdBoard[] = {
   B00000000,   
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};
byte fourthBoard[] = {
   B00000000,   
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};




void setup() {
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  lc.shutdown(3,false);
  lc.setIntensity(0,2);  // Set intensity levels
  lc.setIntensity(1,2);
  lc.setIntensity(2,2);
  lc.setIntensity(3,2);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
  Serial.begin(9600);
  
  
}

void initial_dikhane_vala()
{
  for (int i = 0; i < 8; i++)  
  { lc.setRow(3,i,firstBoard[i]);
    lc.setRow(2,i,secondBoard[i]);
   }
}

void update_thirdBoardArray(int digit)
{
  for (int i = 0; i < 8; i++) 
  {
    thirdBoard[i]=initialthirdBoard[i]+IMAGESfirst[digit][i] ; 
  }
}
void update_your_thirdBoardArray(int digit)
{
  for (int i = 0; i < 8; i++) 
  {
    thirdBoard[i]=yourThird[i]+IMAGESfirst[digit][i] ; 
  }
}


void update_fourthBoardArray(int tensPlace,int oncePlace)
{
  for (int i = 0; i < 8; i++) 
  {
    fourthBoard[i]=IMAGESsecond[tensPlace][i]+IMAGESlast[oncePlace][i]; 
  }
}
 

 
 
 
void loop() {
    int highScore=71;
    int tensPlace=highScore/10;
    update_thirdBoardArray(tensPlace);
    update_fourthBoardArray(tensPlace,highScore%10);
    for (int i = 0; i < 8; i++)  
    { 
     lc.setRow(3,i,firstBoard[i]);
    lc.setRow(2,i,secondBoard[i]);
    lc.setRow(1,i,thirdBoard[i]);
    lc.setRow(0,i,fourthBoard[i]);
   }

    delay(delayTime);
    if(Serial.available()){
      int playerScore=Serial.read();
    }
    tensPlace=playerScore/10;

    update_your_thirdBoardArray(tensPlace);
    update_fourthBoardArray(tensPlace,playerScore%10);
    for (int i = 0; i < 8; i++)  
    { 
     lc.setRow(3,i,yourFirst[i]);
    lc.setRow(2,i,yourSecond[i]);
    lc.setRow(1,i,thirdBoard[i]);
    lc.setRow(0,i,fourthBoard[i]);
   }

   delay(delayTime);
    
 
}
