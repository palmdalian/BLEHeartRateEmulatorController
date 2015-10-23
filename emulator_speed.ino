          // the number of pins (i.e. the length of the array)

void setup()   /****** SETUP: RUNS ONCE ******/
{

  // initialize serial:
  Serial.begin(9600);
  Serial1.begin(9600);
  Keyboard.begin();
  while (! Serial1); // Wait until Serial is ready - Leonardo Arduino
  
  delay(4000); //Check that all relays are inactive at Reset
  Serial.println("Ready to start");
  
}//--(end setup )---

void loop() 
{
  if (Serial1.available())
  {
    char ch = Serial1.read();  //looking for characters on the serial port from the python script 
    if (ch == '0'){
      Serial.print(ch);
      Keyboard.press(KEY_F9);
      delay(100);
      Keyboard.releaseAll();
    }
    else if (ch == '1') {
      Serial.print(ch);
      Keyboard.press(KEY_F10);
      Keyboard.releaseAll();
    }
  }
}
