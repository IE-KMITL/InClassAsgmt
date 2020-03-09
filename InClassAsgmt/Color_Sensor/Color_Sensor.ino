int analogPin = A5; 
int val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);   
  if ((val>2600)&&(val<2800))
 { Serial.print("val = "); 
  Serial.println("Yellow");} 
  else if ((val>2900)&&(val<3000))
  { Serial.print("val = "); 
  Serial.println("Green");} 
  else if ((val>3000)&&(val<3300))
  { Serial.print("val = "); 
  Serial.println("Blue");} 
  else
  { Serial.print("val = "); 
  Serial.println("object not found");} 
  delay(1);
 
}
  
