


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

   if (Serial.available() > 0) {
    // read the incoming byte:
      digitalWrite(12,HIGH);
    
    // say what you got:
    
   }
   
  

}
