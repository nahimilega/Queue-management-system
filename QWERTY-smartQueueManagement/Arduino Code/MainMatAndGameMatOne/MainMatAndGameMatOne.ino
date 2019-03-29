int matOneStatusLed = 6;  

int matOneGameled1 = 5;  
int matOneGameled2 = 4;  
int matOneGameled3 = 3;  
int matOneGameled4 = 2;  

int matOneStatusButton = 9;  
int matOneGameButton1 = 10;   
int matOneGameButton2 = 11;  
int matOneGameButton3 = 12;   
int matOneGameButton4 = 13; 

int indexForMat1 = 0; //justa a helper variable for mat one status button
int gameIndex = 0; // used to start game

int scoreMat1 = 0;

long randomNumber;

int mainMatStatusLed = 7;
int mainMatStatusButton = 8;

int countMainButtonPress = 0;
int countMat1ButtonPress = 1;
uint32_t mainButtonStartTime = 0;
uint32_t mainButtonDuration = 0;
uint32_t mat1StartTime = 0;
uint32_t mat1Duration = 0;

int mainMatCountIndex = 0;  //counts the person number on mat 1

int callingMat1Index = 1;




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

  pinMode(mainMatStatusButton, INPUT);
  pinMode(mainMatStatusLed, OUTPUT);
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
    if(digitalRead(mainMatStatusButton) == HIGH){
      
      turnAllLedOff();
      digitalWrite(mainMatStatusLed, HIGH);
      digitalWrite(matOneStatusLed, HIGH);
      mainButtonDuration = millis() - mainButtonStartTime;
      
      if(mainMatCountIndex == 1){
        mainButtonDuration = millis() - mainButtonStartTime;
        mainMatCountIndex = 0;
          
        Serial.print("***main ");
        Serial.print(countMainButtonPress);
        Serial.print(" ");
        Serial.print(mainButtonDuration);
        Serial.println(" ###");
        scoreMat1 = 0;
      
      }   
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
  int mainMatIndex = 0;
  delay(10);
  if(digitalRead(mainMatStatusButton) == LOW){
    
    mainMatIndex = 1;
    
    
    
    if(mainMatCountIndex == 0){

      Serial.println("main mat on");
      mainMatCountIndex = 1;
      countMainButtonPress += 1;
      mainButtonStartTime = millis();
      digitalWrite(mainMatStatusLed, LOW); 
      
    }
    
  }
  else if(digitalRead(mainMatStatusButton) == HIGH){
    
    mainMatIndex = 0;
    digitalWrite(mainMatStatusLed, HIGH);
    

    if(mainMatCountIndex == 1){
        mainButtonDuration = millis() - mainButtonStartTime;
        mainMatCountIndex = 0;
        
        
        Serial.print("***main p");
        Serial.print(countMainButtonPress);
        Serial.print(" d");
        Serial.print(mainButtonDuration);
        Serial.print(" mat1 p");
        Serial.print(countMat1ButtonPress);
        Serial.print(" d");
        Serial.print(mat1Duration);
        Serial.print(" s");
        Serial.print(scoreMat1);
        Serial.println(" ###");
        scoreMat1 = 0;
      
    }
    
  }
  if (digitalRead(matOneStatusButton) == LOW && mainMatIndex == 1){

      if(indexForMat1 == 0){

        Serial.println("mat 1 on");
        
        countMat1ButtonPress += 1;
        mat1StartTime = millis();
        
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
        while(digitalRead(matOneStatusButton) == LOW && digitalRead(mainMatStatusButton == LOW)){
          startGameOne();
        }
        gameIndex = 0;
      }
    
  }
  
  else{
      if(indexForMat1 == 1){

        mat1Duration = millis() - mat1StartTime;
        
        Serial.print("***mat1 p");
        Serial.print(countMat1ButtonPress);
        Serial.print(" d");
        Serial.print(mat1Duration);
        Serial.print(" s");
        Serial.print(scoreMat1);
        Serial.println(" ###");
        
        indexForMat1 = 0;
      }
        
      digitalWrite(matOneStatusLed, HIGH);

      digitalWrite(matOneGameled1, HIGH);
      digitalWrite(matOneGameled2, HIGH);
      digitalWrite(matOneGameled3, HIGH);
      digitalWrite(matOneGameled4, HIGH);
  }  
}




// loop function starts:
void loop() {
      mat1();
    
    

}
