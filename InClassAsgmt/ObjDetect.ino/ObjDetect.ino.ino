int ledPin = D3;

int digitalPin = D4;

int val = 0;

void setup() {

  pinMode(ledPin, OUTPUT);  

  pinMode(digitalPin, INPUT); 

  Serial.begin(9600);

}



void loop() {

  val = digitalRead(digitalPin);  

  Serial.print("val = "); 

  Serial.println(val); 

  if (val == 0) { 

    digitalWrite(ledPin, HIGH); 

  }

  else {

    digitalWrite(ledPin, LOW); 

  }

  delay(100);

}

//จากการทดลองวัตถุต่างๆ 5 ชนิดได้ผลการทดลองดังต่อไปนี้
 //1.กระเป๋าดินสอสีเขียวอ่อน จับได้ในระยะ 11 ซม.
 //2.กระเป๋าตังค์สีครีม จับได้ในระยะ 9 ซม.
 //3.โทรศัพท์สีส้ม จับได้ในระยะ 10 ซม.
 //4.บัตรสีดำ จับได้ในระยะ 4.5 ซม.
 //5.เมาส์สีแดง จับได้ในระยะ 10.5 ซม. 
 // สรุปได้ว่า จากการทดลองพบว่าวัตถุอื่นๆจับระยะได้น้อยกว่า 15 ซม.เพราะกระดาษสีขาวสะท้อนแสงได้ดีกว่า 
