int matOneStatusLed = 7;  

int matOneGameled1 = 6;  
int matOneGameled2 = 5;  
int matOneGameled3 = 4;  
int matOneGameled4 = 3;  

int matOneStatusButton = 8;  
int matOneGameButton1 = 9;   
int matOneGameButton2 = 10;  
int matOneGameButton3 = 11;   
int matOneGameButton4 = 12; 

int indexForMat1 = 0; //justa a helper variable for mat one status button
int gameIndex = 0; // used to start game

int scoreMat1 = 0;

long randomNumber;

int countMat1ButtonPress = 2;
uint32_t mat1StartTime = 0;
uint32_t mat1Duration = 0;

int startIndex = 0;
int callingMat1Index = 0;
int timepass;





void setup() {
  
  Serial.begin(2000000);
  
  pinMode(matOneGameled1, OUTPUT);
  pinMode(matOneGameled2, OUTPUT);
  pinMode(matOneGameled3, OUTPUT);
  pinMode(matOneGameled4, OUTPUT);
  pinMode(matOneStatusLed, OUTPUT);

  pinMode(matOneStatusButton, INPUT);
  pinMode(matOneGameButton1, INPUT);
  pinMode(matOneGameButton2, INPUT);
  pinMode(matOneGameButton3, INPUT);
  pinMode(matOneGameButton4, INPUT);

  randomSeed(analogRead(0));

}




//simple function to turn all led's off
void turnAllLedOff(){
  digitalWrite(matOneGameled1, HIGH);
  digitalWrite(matOneGameled2, HIGH);
  digitalWrite(matOneGameled3, HIGH);
  digitalWrite(matOneGameled4, HIGH);
}




// startGameone function starts here:
void startGameOne(){

    randomNumber = random(1, 5);

  // checks if main mat status is not off
     checkingPersonTwo();
    if(callingMat1Index == 0){

      mat1Duration = millis() - mat1StartTime;
      
      turnAllLedOff();
      digitalWrite(matOneStatusLed, HIGH);

      return; 
    }

    
    if (randomNumber == 1){
  
      turnAllLedOff();
      digitalWrite(matOneGameled1, LOW);
      uint32_t ts1 = millis();
  
      //if time is less than 2 seconds, and the correct button is pressed then score is increased
      while(millis() - ts1 < 2000){
          
        if(digitalRead(matOneGameButton1) == LOW){
          scoreMat1 += 1;
          break;
        }
      }
      
    }
    
    else if(randomNumber == 2){
      
      turnAllLedOff();
      digitalWrite(matOneGameled2, LOW);
      uint32_t ts1 = millis();
  
      //if time is less than 2 seconds, and the correct button is pressed then score is increased
      while(millis() - ts1 < 2000){
          
        if(digitalRead(matOneGameButton2) == LOW){
          scoreMat1 += 1;
          break;
        }
      }
      
    }
    else if(randomNumber == 3){

      turnAllLedOff();
      digitalWrite(matOneGameled3, LOW);
      uint32_t ts1 = millis();
  
      //if time is less than 3 seconds, and the correct button is pressed then score is increased
      while(millis() - ts1 < 2000){
          
        if(digitalRead(matOneGameButton3) == LOW){
          scoreMat1 += 1;
          break;
          
        }
      }
      
    }
    else if(randomNumber == 4){

      turnAllLedOff();
      digitalWrite(matOneGameled4, LOW);
      uint32_t ts1 = millis();
  
      //if time is less than 3 seconds, and the correct button is pressed then score is increased
      while(millis() - ts1 < 2000){
          
        if(digitalRead(matOneGameButton4) == LOW){
          scoreMat1 += 1;
          break;
        }
      }
    }

  
}



//mat1 function starts:

void mat1(){

  if (digitalRead(matOneStatusButton) == LOW && callingMat1Index == 1){

   

      if(indexForMat1 == 0){

        
        countMat1ButtonPress += 1;
        mat1StartTime = millis();

        Serial.println("mat 3 on");
        
        indexForMat1 = 1;
      }
      
      digitalWrite(matOneStatusLed, LOW);
  
      digitalWrite(matOneGameled1, LOW);
      digitalWrite(matOneGameled2, LOW);
      digitalWrite(matOneGameled3, LOW);
      digitalWrite(matOneGameled4, LOW);
  
      if(digitalRead(matOneGameButton1) == LOW && gameIndex == 0){
        gameIndex = 1;
       
      }
      if(digitalRead(matOneGameButton2) == LOW && gameIndex == 1){
        gameIndex = 2;
       
        
      }
      if(digitalRead(matOneGameButton3) == LOW && gameIndex == 2){
        gameIndex = 3;
 
      }
      if(digitalRead(matOneGameButton4) == LOW && gameIndex == 3){
        gameIndex = 4;
        while(digitalRead(matOneStatusButton) == LOW && callingMat1Index == 1){
          startGameOne();
        }
        gameIndex = 0;
      }
    
  }
  
  else{
      if(indexForMat1 == 1){
        
        mat1Duration = millis() - mat1StartTime;
  
        Serial.print(" mat3 p");
        Serial.print(countMat1ButtonPress);
        Serial.print(" d");
        Serial.print(mat1Duration);
        Serial.print(" s");
        Serial.print(scoreMat1);
        Serial.println(" ###");
        
        indexForMat1 = 0;
        scoreMat1 = 0;
      }
        
      digitalWrite(matOneStatusLed, HIGH);

      digitalWrite(matOneGameled1, HIGH);
      digitalWrite(matOneGameled2, HIGH);
      digitalWrite(matOneGameled3, HIGH);
      digitalWrite(matOneGameled4, HIGH);
  }  
}


void checkingPersonTwo(){

  if(Serial.available()){

   switch(Serial.read()){

      case '1': callingMat1Index = 1;
                break;
                
      case '0': callingMat1Index = 0;
                break;
                
      default: break;
   }
    
  } 
}

// loop function starts:
void loop() {

  checkingPersonTwo();  
  mat1();
  
}
