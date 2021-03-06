int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter += 1;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(5); // Wait for 5 millisecond(s)
  }
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState = buttonState;
  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the devision of two numbers
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}